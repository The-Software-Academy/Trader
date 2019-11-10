#include "apiconversation.hpp"

#include "../apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace core {
namespace apiclient {

ApiConversation::ApiConversation(const core::bom::ApiRequest & iRequest,
                                 QObject* parent = 0):
    QObject(parent), mRequest(iRequest)
{}

void ApiConversation::setApiResponseBuilder(const QSharedPointer<const ApiResponseBuilder> & iResponseBuilder)
{
    mResponseBuilder = iResponseBuilder;
}

void ApiConversation::decodeReply(const QString& iReply) const
{
    emit responseReady(core::bom::ApiResponse{mResponseBuilder->build(iReply)});
}

}
}
}

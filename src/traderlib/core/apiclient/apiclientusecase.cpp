#include "apiclientusecase.hpp"

#include <QNetworkAccessManager>
#include <QNetworkRequest>

#include "apiclientdata.hpp"
#include "apiconversation.hpp"
#include "apirequestbuilder.hpp"
#include "apirequestbuilder.hpp"

namespace bitinvest {
namespace core {
namespace apiclient {

ApiClientUsecase::ApiClientUsecase(
        const QSharedPointer<const DependenciesFactory> & iFactory,
        const QSharedPointer<QNetworkAccessManager>& iNetworkAccessManager,
        const QSharedPointer<const ApiClientData> & iApiClientData):
    mFactory(iFactory), mNetworkAccessManager(iNetworkAccessManager), mApiClientData(iApiClientData)
{}

void ApiClientUsecase::execute(ApiConversation & iApiConversation)
{
    QNetworkRequest aNetworkRequest(
                mApiClientData->getApiHostAddress().toString() + mFactory->getRequestBuilder()
                                    ->build(iApiConversation.mRequest));
    iApiConversation.setApiResponseBuilder(mFactory->getResponseBuilder());
    aNetworkRequest.setOriginatingObject(&iApiConversation);
    aNetworkRequest.setRawHeader(QByteArray("Authorization"), mApiClientData->getAuthentication().
                                 toLatin1());
    (*mNetworkAccessManager.*mFactory->getHttpMethod())(aNetworkRequest);
}


}
}
}


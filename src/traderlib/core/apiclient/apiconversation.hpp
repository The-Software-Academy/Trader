#ifndef BITINVESTREQUEST_H
#define BITINVESTREQUEST_H

#include<QObject>

#include <QSharedPointer>

#include "../bom/apirequest.hpp"
#include "../bom/apiresponse.hpp"
#include "../bom/apierror.hpp"


namespace bitinvest {
namespace core {
namespace apiclient {

class ApiResponseBuilder;

class ApiConversation: public QObject
{
Q_OBJECT
public:
    ApiConversation(const core::bom::ApiRequest &, QObject*);

    const core::bom::ApiRequest mRequest;

    void setApiResponseBuilder(const QSharedPointer<const ApiResponseBuilder> &);

public slots:
    void decodeReply(const QString&) const;

signals:
    void responseReady(bitinvest::core::bom::ApiResponse) const;
    void requestError(bitinvest::core::bom::ApiError) const;

private:
    QSharedPointer<const apiclient::ApiResponseBuilder> mResponseBuilder;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::apiclient::ApiConversation*)

#endif // BITINVESTREQUEST_H

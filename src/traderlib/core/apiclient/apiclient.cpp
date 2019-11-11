#include "apiclient.hpp"

#include "apiclientusecase.hpp"
#include "unexpectedparameterstype.hpp"
#include "unhandledrequesttype.hpp"

namespace bitinvest {
namespace core {
namespace apiclient {


ApiClient::ApiClient(
        const ApiTypeAdaptersMap & iMap,
        const QSharedPointer<const ApiClientData> & iData,
        QObject *parent) :
    QObject(parent),
    mAdaptersMap(iMap),
    mData(iData),
    mNetworkAccess(QSharedPointer<QNetworkAccessManager>::create(
                       new QNetworkAccessManager()))
{
    mNetworkAccess->connectToHostEncrypted(
                mData->getApiHostAddress().toString());
    connect(mNetworkAccess.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(getReply(QNetworkReply*)));
}

void ApiClient::send(core::apiclient::ApiConversation * const iApiConversation) const
{
    try
    {
        ApiClientUsecase(mAdaptersMap.getAdapters(iApiConversation->mRequest), mNetworkAccess, mData).execute(*iApiConversation);
    }
    catch(UnhandledRequestType)
    {
        /** @todo handle this exception with a signal*/
    }
    catch(UnexpectedParametersType)
    {
        /** @todo this exception is a fatal error due to a wrong mapping of at least one
         * usecase dependencies factories in the code solvable only by recompile*/
    }
}

void ApiClient::getReply(QNetworkReply* iReply) const
{
    QMetaObject::invokeMethod(iReply->request().originatingObject(), "decodeReply",  Qt::DirectConnection, Q_ARG(const QString&, iReply->readAll()));
}

}
}
}

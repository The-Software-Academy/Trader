#ifndef APICLIENT_HPP
#define APICLIENT_HPP

#include <QNetworkReply>
#include <QObject>
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include "apiconversation.hpp"
#include "apiclientdata.hpp"
#include "apitypeadaptersmap.hpp"

namespace bitinvest{
namespace core {
namespace apiclient {




class ApiClient : public QObject
{
    Q_OBJECT
public:
    explicit ApiClient(
            const ApiTypeAdaptersMap &,
            const QSharedPointer<const ApiClientData> &,
            QObject *parent = nullptr);

public slots:
    void send(bitinvest::core::apiclient::ApiConversation *) const;
    void getReply(QNetworkReply*) const;

private:
    const ApiTypeAdaptersMap mAdaptersMap;
    const QSharedPointer<const ApiClientData> mData;
    QSharedPointer<QNetworkAccessManager> mNetworkAccess;

};


}
}
}

#endif // APICLIENT_HPP

#ifndef APICLIENTUSECASE_HPP
#define APICLIENTUSECASE_HPP

#include <QSharedPointer>
#include <QNetworkAccessManager>

namespace bitinvest {
namespace core {
namespace apiclient {

class ApiResponseBuilder;
class ApiRequestBuilder;
class ApiConversation;
class ApiClientData;

typedef QNetworkReply * (QNetworkAccessManager::* HttpMethod)(const QNetworkRequest &request);

class ApiClientUsecase
{
public:
    class DependenciesFactory
    {

    public:
        virtual ~DependenciesFactory() = default;
        virtual const QSharedPointer<const ApiRequestBuilder> getRequestBuilder() const = 0;
        virtual const QSharedPointer<const ApiResponseBuilder> getResponseBuilder() const = 0;
        virtual HttpMethod getHttpMethod() const = 0;
    };
    explicit ApiClientUsecase(
            const QSharedPointer<const DependenciesFactory> &,
            const QSharedPointer<QNetworkAccessManager> &,
            const QSharedPointer<const ApiClientData> &);
    void execute(ApiConversation &);
private:
    QSharedPointer<const DependenciesFactory> mFactory;
    QSharedPointer<QNetworkAccessManager> mNetworkAccessManager;
    QSharedPointer<const ApiClientData> mApiClientData;
};

}
}
}



#endif // APICLIENTUSECASE_HPP

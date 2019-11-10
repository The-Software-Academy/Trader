#include "currenciesdependenciesfactory.hpp"

#include "currenciesrequestbuilder.hpp"
#include "currenciesresponsebuilder.hpp"
#include <core/apiclient/apirequestbuilder.hpp>
#include <core/apiclient/apiresponsebuilder.hpp>


namespace bitinvest {
namespace apiclient {
namespace hitbtc {

CurrenciesDependenciesFactory::CurrenciesDependenciesFactory()
{

}

const QSharedPointer<const core::apiclient::ApiRequestBuilder> CurrenciesDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<CurrenciesRequestBuilder>::create();
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> CurrenciesDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<CurrenciesResponseBuilder>::create();
}

core::apiclient::HttpMethod CurrenciesDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

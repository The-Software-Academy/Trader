#include "candlesdependenciesfactory.hpp"

#include "candlesrequestbuilder.hpp"
#include "candlesresponsebuilder.hpp"
#include <core/apiclient/apirequestbuilder.hpp>
#include <core/apiclient/apiresponsebuilder.hpp>


namespace bitinvest {
namespace apiclient {
namespace hitbtc {

CandlesDependenciesFactory::CandlesDependenciesFactory()
{

}

const QSharedPointer<const core::apiclient::ApiRequestBuilder> CandlesDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<CandlesRequestBuilder>::create();
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> CandlesDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<CandlesResponseBuilder>::create();
}

core::apiclient::HttpMethod CandlesDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

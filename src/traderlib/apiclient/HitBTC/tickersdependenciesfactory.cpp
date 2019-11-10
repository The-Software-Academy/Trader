#include "tickersdependenciesfactory.hpp"

#include "tickersrequestbuilder.hpp"
#include "tickersresponsebuilder.hpp"
#include <core/apiclient/apirequestbuilder.hpp>
#include <core/apiclient/apiresponsebuilder.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

TickersDependenciesFactory::TickersDependenciesFactory()
{

}

const QSharedPointer<const core::apiclient::ApiRequestBuilder> TickersDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<TickersRequestBuilder>::create();
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> TickersDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<TickersResponseBuilder>::create();
}

core::apiclient::HttpMethod TickersDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

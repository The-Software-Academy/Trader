#include "orderbookdependenciesfactory.hpp"

#include "orderbookrequestbuilder.hpp"
#include "orderbookresponsebuilder.hpp"
#include <core/apiclient/apirequestbuilder.hpp>
#include <core/apiclient/apiresponsebuilder.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

OrderbookDependenciesFactory::OrderbookDependenciesFactory()
{

}

const QSharedPointer<const core::apiclient::ApiRequestBuilder> OrderbookDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<OrderbookRequestBuilder>::create();
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> OrderbookDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<OrderbookResponseBuilder>::create();
}

core::apiclient::HttpMethod OrderbookDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

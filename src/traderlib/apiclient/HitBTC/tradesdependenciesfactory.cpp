#include "tradesdependenciesfactory.hpp"

#include "tradesrequestbuilder.hpp"
#include "tradesresponsebuilder.hpp"
#include "dataspecifierformatter.hpp"
#include "filterspecifierformatter.hpp"

#include <core/apiclient/apirequestbuilder.hpp>
#include <core/apiclient/apiresponsebuilder.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

TradesDependenciesFactory::TradesDependenciesFactory()
{

}

const QSharedPointer<const core::apiclient::ApiRequestBuilder> TradesDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<TradesRequestBuilder>::create(
                QSharedPointer<DataSpecifierFormatter>::create(),
                QSharedPointer<FilterSpecifierFormatter>::create());
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> TradesDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<TradesResponseBuilder>::create();
}

core::apiclient::HttpMethod TradesDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

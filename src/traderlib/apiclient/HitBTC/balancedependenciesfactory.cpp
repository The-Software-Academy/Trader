#include "balancedependenciesfactory.hpp"

#include "balancerequestbuilder.hpp"
#include "balanceresponsebuilder.hpp"
#include "../../core/apiclient/apirequestbuilder.hpp"
#include "../../core/apiclient/apiresponsebuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {


BalanceDependenciesFactory::BalanceDependenciesFactory()
{

}


const QSharedPointer<const core::apiclient::ApiRequestBuilder> BalanceDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<BalanceRequestBuilder>::create();
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> BalanceDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<BalanceResponseBuilder>::create();
}

core::apiclient::HttpMethod BalanceDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

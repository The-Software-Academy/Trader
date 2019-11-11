#ifndef BALANCEDEPENDENCIESFACTORY_HPP
#define BALANCEDEPENDENCIESFACTORY_HPP

#include "../../core/apiclient/apiclientusecase.hpp"

namespace bitinvest {

namespace core {
namespace apiclient {
class ApiRequestBuilder;
class ApiResponseBuilder;
}
}

namespace apiclient {
namespace hitbtc {

class BalanceDependenciesFactory: public core::apiclient::ApiClientUsecase::DependenciesFactory
{
public:
    BalanceDependenciesFactory();
    const QSharedPointer<const core::apiclient::ApiRequestBuilder> getRequestBuilder() const override;
    const QSharedPointer<const core::apiclient::ApiResponseBuilder> getResponseBuilder() const override;
    core::apiclient::HttpMethod getHttpMethod() const override;
};

}
}
}



#endif // BALANCEDEPENDENCIESFACTORY_HPP

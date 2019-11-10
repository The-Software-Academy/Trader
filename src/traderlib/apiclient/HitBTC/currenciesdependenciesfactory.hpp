#ifndef CURRENCIESDEPENDENCIESFACTORY_HPP
#define CURRENCIESDEPENDENCIESFACTORY_HPP

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

class CurrenciesDependenciesFactory: public core::apiclient::ApiClientUsecase::DependenciesFactory
{
public:
    CurrenciesDependenciesFactory();
    const QSharedPointer<const core::apiclient::ApiRequestBuilder> getRequestBuilder() const override;
    const QSharedPointer<const core::apiclient::ApiResponseBuilder> getResponseBuilder() const override;
    core::apiclient::HttpMethod getHttpMethod() const override;
};

}
}
}

#endif // CURRENCIESDEPENDENCIESFACTORY_HPP

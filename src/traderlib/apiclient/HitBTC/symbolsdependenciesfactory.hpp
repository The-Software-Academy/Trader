#ifndef SYMBOLSDEPENDENCIESFACTORY_HPP
#define SYMBOLSDEPENDENCIESFACTORY_HPP

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

class SymbolsDependenciesFactory: public core::apiclient::ApiClientUsecase::DependenciesFactory
{
public:
    SymbolsDependenciesFactory();
    const QSharedPointer<const core::apiclient::ApiRequestBuilder> getRequestBuilder() const override;
    const QSharedPointer<const core::apiclient::ApiResponseBuilder> getResponseBuilder() const override;
    core::apiclient::HttpMethod getHttpMethod() const override;
};

}
}
}

#endif // SYMBOLSDEPENDENCIESFACTORY_HPP

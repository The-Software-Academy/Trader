#include "symbolsdependenciesfactory.hpp"

#include "symbolsrequestbuilder.hpp"
#include "symbolsresponsebuilder.hpp"
#include <core/apiclient/apirequestbuilder.hpp>
#include <core/apiclient/apiresponsebuilder.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

SymbolsDependenciesFactory::SymbolsDependenciesFactory()
{

}

const QSharedPointer<const core::apiclient::ApiRequestBuilder> SymbolsDependenciesFactory::getRequestBuilder() const
{
    return QSharedPointer<SymbolsRequestBuilder>::create();
}

const QSharedPointer<const core::apiclient::ApiResponseBuilder> SymbolsDependenciesFactory::getResponseBuilder() const
{
    return QSharedPointer<SymbolsResponseBuilder>::create();
}

core::apiclient::HttpMethod SymbolsDependenciesFactory::getHttpMethod() const
{
    return &QNetworkAccessManager::get;
}

}
}
}

#ifndef SYMBOLSREQUESTBUILDER_HPP
#define SYMBOLSREQUESTBUILDER_HPP

#include "../../core/apiclient/apirequestbuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {


class SymbolsRequestBuilder : public core::apiclient::ApiRequestBuilder
{
public:
    SymbolsRequestBuilder();
    QString build(const core::bom::ApiRequest &) const override;
};

}
}
}

#endif // SYMBOLSREQUESTBUILDER_HPP

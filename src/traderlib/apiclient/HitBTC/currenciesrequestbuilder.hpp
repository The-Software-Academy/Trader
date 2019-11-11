#ifndef CURRENCIESREQUESTBUILDER_HPP
#define CURRENCIESREQUESTBUILDER_HPP

#include "../../core/apiclient/apirequestbuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {


class CurrenciesRequestBuilder : public core::apiclient::ApiRequestBuilder
{
public:
    CurrenciesRequestBuilder();
    QString build(const bitinvest::core::bom::ApiRequest &) const override;
};

}
}
}

#endif // CURRENCIESREQUESTBUILDER_HPP

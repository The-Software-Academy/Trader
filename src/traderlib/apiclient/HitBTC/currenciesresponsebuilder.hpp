#ifndef CURRENCIESRESPONSEBUILDER_HPP
#define CURRENCIESRESPONSEBUILDER_HPP

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class CurrenciesResponseBuilder : public bitinvest::core::apiclient::ApiResponseBuilder
{
public:
    CurrenciesResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}


#endif // CURRENCIESRESPONSEBUILDER_HPP

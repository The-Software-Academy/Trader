#ifndef SYMBOLSRESPONSEBUILDER_HPP
#define SYMBOLSRESPONSEBUILDER_HPP

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class SymbolsResponseBuilder : public bitinvest::core::apiclient::ApiResponseBuilder
{
public:
    SymbolsResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}

#endif // SYMBOLSRESPONSEBUILDER_HPP

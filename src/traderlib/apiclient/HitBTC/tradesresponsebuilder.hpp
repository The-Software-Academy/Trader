#ifndef TRADESRESPONSEBUILDER_HPP
#define TRADESRESPONSEBUILDER_HPP

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class TradesResponseBuilder : public core::apiclient::ApiResponseBuilder
{
public:
    TradesResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}

#endif // TRADESRESPONSEBUILDER_HPP

#ifndef ORDERBOOKRESPONSEBUILDER_HPP
#define ORDERBOOKRESPONSEBUILDER_HPP

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class OrderbookResponseBuilder : public core::apiclient::ApiResponseBuilder
{
public:
    OrderbookResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}

#endif // ORDERBOOKRESPONSEBUILDER_HPP

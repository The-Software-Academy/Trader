#ifndef HITBTCBALANCERESPONSEBUILDER_H
#define HITBTCBALANCERESPONSEBUILDER_H

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class BalanceResponseBuilder : public core::apiclient::ApiResponseBuilder
{
public:
    BalanceResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}


#endif // HITBTCBALANCERESPONSEBUILDER_H

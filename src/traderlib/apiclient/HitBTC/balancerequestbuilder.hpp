#ifndef HITBTCTRADINGBALANCEREQUESTBUILDER_H
#define HITBTCTRADINGBALANCEREQUESTBUILDER_H

#include "../../core/apiclient/apirequestbuilder.hpp"
#include <QString>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class BalanceRequestBuilder : public core::apiclient::ApiRequestBuilder
{
public:
    BalanceRequestBuilder();
    QString build(const core::bom::ApiRequest &) const override;
};

}
}
}



#endif // HITBTCTRADINGBALANCEREQUESTBUILDER_H

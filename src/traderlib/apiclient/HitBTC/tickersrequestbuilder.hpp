#ifndef HITBTCTICKERSREQUESTBUILDER_HPP
#define HITBTCTICKERSREQUESTBUILDER_HPP

#include "../../core/apiclient/apirequestbuilder.hpp"
#include <QString>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class TickersRequestBuilder: public core::apiclient::ApiRequestBuilder
{
public:
    TickersRequestBuilder();
    QString build(const core::bom::ApiRequest &) const override;
};

}
}
}

#endif // HITBTCTICKERSREQUESTBUILDER_HPP

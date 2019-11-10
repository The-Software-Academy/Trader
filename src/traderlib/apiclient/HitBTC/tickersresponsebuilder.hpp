#ifndef HITBTCTICKERSRESPONSE_HPP
#define HITBTCTICKERSRESPONSE_HPP

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class TickersResponseBuilder : public core::apiclient::ApiResponseBuilder
{
public:
    TickersResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}


#endif // HITBTCTICKERSRESPONSE_HPP

#ifndef CANDLESRESPONSEBUILDER_HPP
#define CANDLESRESPONSEBUILDER_HPP

#include "../../core/apiclient/apiresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class CandlesResponseBuilder : public core::apiclient::ApiResponseBuilder
{
public:
    CandlesResponseBuilder();
    QByteArray build(const QString &) const override;
};

}
}
}

#endif // CANDLESRESPONSEBUILDER_HPP

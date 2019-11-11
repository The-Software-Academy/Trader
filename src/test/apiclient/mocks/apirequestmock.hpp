#ifndef APIREQUESTMOCK_HPP
#define APIREQUESTMOCK_HPP

#include <gmock/gmock.h>
#include "../traderlib/core/bom/apirequest.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class ApiRequestMock: public bitinvest::core::bom::ApiRequest
{
public:
    ApiRequestMock(): ApiRequest(QVariant::Invalid){}
    ApiRequestMock(const QVariant & iVariant): ApiRequest(iVariant){}
};

}
}
}
}

#endif // APIREQUESTMOCK_HPP

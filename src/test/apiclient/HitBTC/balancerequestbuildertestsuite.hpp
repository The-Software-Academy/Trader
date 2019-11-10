#ifndef BALANCEREQUESTBUILDERTESTSUITE_HPP
#define BALANCEREQUESTBUILDERTESTSUITE_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../traderlib/apiclient/HitBTC/balancerequestbuilder.hpp"

#include <QtNetwork/QNetworkRequest>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

TEST(BalanceRequestBuilderTestSuite, WrongParametersType)
{
    core::bom::ApiRequest aRequest(core::bom::TickersParameters{});
    ASSERT_THROW(BalanceRequestBuilder().build(aRequest), core::apiclient::UnexpectedParametersType);
}

TEST(BalanceRequestBuilderTestSuite, SuccessCase)
{
    core::bom::ApiRequest aRequest(core::bom::BalanceParameters{});
    ASSERT_STREQ(BalanceRequestBuilder().build(aRequest).toStdString().c_str(),
                 "trading/balance");
}

}
}
}
}


#endif // BALANCEREQUESTBUILDERTESTSUITE_HPP

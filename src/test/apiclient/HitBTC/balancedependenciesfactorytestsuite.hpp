#ifndef BALANCEDEPENDENCIESFACTORYTESTSUITE_HPP
#define BALANCEDEPENDENCIESFACTORYTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../traderlib/apiclient/HitBTC/balancedependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/balancerequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/balanceresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class BalanceDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    BalanceDependenciesFactory factory;
};

TEST_F(BalanceDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const BalanceRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(BalanceDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const BalanceResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(BalanceDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}

#endif // BALANCEDEPENDENCIESFACTORYTESTSUITE_HPP

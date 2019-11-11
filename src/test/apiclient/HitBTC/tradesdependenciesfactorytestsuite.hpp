#ifndef TRADESDEPENDENCIESFACTORYTESTSUITE_HPP
#define TRADESDEPENDENCIESFACTORYTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../traderlib/apiclient/HitBTC/tradesdependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/tradesrequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/tradesresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class TradesDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    TradesDependenciesFactory factory;
};

TEST_F(TradesDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const TradesRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(TradesDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const TradesResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(TradesDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}

#endif // TRADESDEPENDENCIESFACTORYTESTSUITE_HPP

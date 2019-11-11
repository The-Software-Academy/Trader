#ifndef TICKERSDEPENDENCIESFACTORYTESTSUITE_HPP
#define TICKERSDEPENDENCIESFACTORYTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../traderlib/apiclient/HitBTC/tickersdependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/tickersrequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/tickersresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class TickersDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    TickersDependenciesFactory factory;
};

TEST_F(TickersDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const TickersRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(TickersDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const TickersResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(TickersDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}

#endif // TICKERSDEPENDENCIESFACTORYTESTSUITE_HPP

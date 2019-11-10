#ifndef CANDLESDEPENDENCIESFACTORYTESTSUITE_HPP
#define CANDLESDEPENDENCIESFACTORYTESTSUITE_HPP

#include "../traderlib/apiclient/HitBTC/candlesdependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/candlesrequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/candlesresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class CandlesDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    CandlesDependenciesFactory factory;
};

TEST_F(CandlesDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const CandlesRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(CandlesDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const CandlesResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(CandlesDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}
#endif // CANDLESDEPENDENCIESFACTORYTESTSUITE_HPP

#ifndef CURRENCIESDEPENDENCIESFACTORYTESTSUITE_HPP
#define CURRENCIESDEPENDENCIESFACTORYTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../traderlib/apiclient/HitBTC/currenciesdependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/currenciesrequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/currenciesresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class CurrenciesDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    CurrenciesDependenciesFactory factory;
};

TEST_F(CurrenciesDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const CurrenciesRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(CurrenciesDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const CurrenciesResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(CurrenciesDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}

#endif // CURRENCIESDEPENDENCIESFACTORYTESTSUITE_HPP

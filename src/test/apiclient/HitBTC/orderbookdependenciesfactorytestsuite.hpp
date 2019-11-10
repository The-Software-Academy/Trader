#ifndef ORDERBOOKDEPENDENCIESFACTORYTESTSUITE_HPP
#define ORDERBOOKDEPENDENCIESFACTORYTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../traderlib/apiclient/HitBTC/orderbookdependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/orderbookrequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/orderbookresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class OrderbookDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    OrderbookDependenciesFactory factory;
};

TEST_F(OrderbookDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const OrderbookRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(OrderbookDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const OrderbookResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(OrderbookDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}

#endif // ORDERBOOKDEPENDENCIESFACTORYTESTSUITE_HPP

#ifndef SYMBOLSDEPENDENCIESFACTORYTESTSUITE_HPP
#define SYMBOLSDEPENDENCIESFACTORYTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../traderlib/apiclient/HitBTC/symbolsdependenciesfactory.hpp"
#include <QNetworkAccessManager>
#include "../traderlib/apiclient/HitBTC/symbolsrequestbuilder.hpp"
#include "../traderlib/apiclient/HitBTC/symbolsresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class SymbolsDependenciesFactoryTestSuite: public ::testing::Test
{
public:
    SymbolsDependenciesFactory factory;
};

TEST_F(SymbolsDependenciesFactoryTestSuite, getRequestBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const SymbolsRequestBuilder&>(*factory.getRequestBuilder()));
}

TEST_F(SymbolsDependenciesFactoryTestSuite, getResponseBuilder)
{
    EXPECT_NO_THROW(
                dynamic_cast<const SymbolsResponseBuilder&>(*factory.getResponseBuilder()));
}

TEST_F(SymbolsDependenciesFactoryTestSuite, getHttpMethod)
{
    EXPECT_TRUE(&QNetworkAccessManager::get == factory.getHttpMethod());
}

}
}
}
}

#endif // SYMBOLSDEPENDENCIESFACTORYTESTSUITE_HPP

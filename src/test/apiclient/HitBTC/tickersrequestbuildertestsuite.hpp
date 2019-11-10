#ifndef TICKERSREQUESTBUILDERTESTSUITE_HPP
#define TICKERSREQUESTBUILDERTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../../../traderlib/apiclient/HitBTC/tickersrequestbuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

TEST(TickersRequestBuilderTestSuite, WrongParametersType)
{
    core::bom::ApiRequest aRequest(core::bom::SymbolsParameters{});
    ASSERT_THROW(TickersRequestBuilder().build(aRequest), core::apiclient::UnexpectedParametersType);
}

TEST(TickersRequestBuilderTestSuite, AllSymbols)
{
    core::bom::ApiRequest aRequest(core::bom::TickersParameters{});
    ASSERT_STREQ(TickersRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/ticker/");
}

TEST(TickersRequestBuilderTestSuite, SingleSymbol)
{
    core::bom::ApiRequest aRequest(bitinvest::core::bom::TickersParameters(
                            QString("ETHBTC")));
    ASSERT_STREQ(TickersRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/ticker/ETHBTC");
}

}
}
}
}

#endif // TICKERSREQUESTBUILDERTESTSUITE_HPP

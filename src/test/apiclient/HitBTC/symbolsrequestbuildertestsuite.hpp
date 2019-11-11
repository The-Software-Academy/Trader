#ifndef SYMBOLSREQUESTBUILDERTESTSUITE_HPP
#define SYMBOLSREQUESTBUILDERTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../../../traderlib/apiclient/HitBTC/symbolsrequestbuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

TEST(SymbolsRequestBuilderTestSuite, WrongParametersType)
{
    core::bom::ApiRequest aRequest(core::bom::TickersParameters{});
    ASSERT_THROW(SymbolsRequestBuilder().build(aRequest), core::apiclient::UnexpectedParametersType);
}

TEST(SymbolsRequestBuilderTestSuite, AllSymbols)
{
    core::bom::ApiRequest aRequest(core::bom::SymbolsParameters{});
    ASSERT_STREQ(SymbolsRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/symbol/");
}

TEST(SymbolsRequestBuilderTestSuite, SymbolOnly)
{
    core::bom::ApiRequest aRequest(bitinvest::core::bom::SymbolsParameters(
                            QString("ETHBTC")));
    ASSERT_STREQ(SymbolsRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/symbol/ETHBTC");
}


}
}
}
}

#endif // SYMBOLSREQUESTBUILDERTESTSUITE_HPP

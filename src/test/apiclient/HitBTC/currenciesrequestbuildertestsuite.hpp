#ifndef CURRENCIESREQUESTBUILDERTESTSUITE_HPP
#define CURRENCIESREQUESTBUILDERTESTSUITE_HPP


#include <gtest/gtest.h>

#include "../../../traderlib/apiclient/HitBTC/currenciesrequestbuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

TEST(CurrenciesRequestBuilderTestSuite, WrongParametersType)
{
    core::bom::ApiRequest aRequest(core::bom::SymbolsParameters{});
    ASSERT_THROW(CurrenciesRequestBuilder().build(aRequest), core::apiclient::UnexpectedParametersType);
}

TEST(CurrenciesRequestBuilderTestSuite, AllIds)
{
    core::bom::ApiRequest aRequest(core::bom::CurrenciesParameters{});
    ASSERT_STREQ(CurrenciesRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/currency/");
}

TEST(CurrenciesRequestBuilderTestSuite, SingleId)
{
    core::bom::ApiRequest aRequest(bitinvest::core::bom::CurrenciesParameters(
                            QString("ETH")));
    ASSERT_STREQ(CurrenciesRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/currency/ETH");
}


}
}
}
}


#endif // CURRENCIESREQUESTBUILDERTESTSUITE_HPP

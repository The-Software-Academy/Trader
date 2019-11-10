#ifndef CANDLESREQUESTBUILDERTESTSUITE_HPP
#define CANDLESREQUESTBUILDERTESTSUITE_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../traderlib/apiclient/HitBTC/candlesrequestbuilder.hpp"
#include <memory>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

TEST(CandlesRequestBuilderTestSuite, EmptyRequest)
{
    const core::bom::ApiRequest aEmptyRequest(core::bom::CandlesParameters{});
    ASSERT_ANY_THROW(CandlesRequestBuilder().build(aEmptyRequest));
}

TEST(CandlesRequestBuilderTestSuite, WrongParametersType)
{
    const core::bom::ApiRequest aWrongRequest(core::bom::OrderbookParameters{});
    ASSERT_THROW(CandlesRequestBuilder().build(aWrongRequest), core::apiclient::UnexpectedParametersType);
}


TEST(CandlesRequestBuilderTestSuite, SymbolOnly)
{
    core::bom::ApiRequest aRequest(core::bom::CandlesParameters(
                                       QString("ETHBTC"),
                                       boost::none));
    ASSERT_STREQ(CandlesRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/candles/ETHBTC");
}

TEST(CandlesRequestBuilderTestSuite, SymbolAndLimit)
{
    core::bom::ApiRequest aRequest(core::bom::CandlesParameters(
                                       QString("ETHBTC"),
                                       core::bom::TimeOffsetDataSpecifier{
                                           core::bom::DataLimit(0U),
                                           boost::none}));
    ASSERT_STREQ(CandlesRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/candles/ETHBTC?limit=0");
}

TEST(CandlesRequestBuilderTestSuite, SymbolAndPeriod)
{
    core::bom::ApiRequest aRequest(core::bom::CandlesParameters(
                            QString("ETHBTC"),
                            core::bom::TimeOffsetDataSpecifier{
                                boost::none,
                                core::bom::TimeOffset("M30")}));

    ASSERT_STREQ(CandlesRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/candles/ETHBTC?period=M30");
}


TEST(CandlesRequestBuilderTestSuite, FullRequest)
{
    core::bom::ApiRequest aRequest(core::bom::CandlesParameters(
                            QString("ETHBTC"),
                            core::bom::TimeOffsetDataSpecifier{
                                core::bom::DataLimit(50),
                                core::bom::TimeOffset("H4")}));

    ASSERT_STREQ(CandlesRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/candles/ETHBTC?limit=50&period=H4");
}


}
}
}
}

#endif // CANDLESREQUESTBUILDERTESTSUITE_HPP

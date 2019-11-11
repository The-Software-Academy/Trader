#ifndef CANDLESPARAMETERSTESTSUITE_HPP
#define CANDLESPARAMETERSTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../../../traderlib/core/bom/candlesparameters.hpp"


namespace bitinvest {
namespace core {
namespace bom {
namespace test {

TEST(CandlesParametersTestSuite, Default)
{
    CandlesParameters aCandlesParameters;

    ASSERT_TRUE(!aCandlesParameters.mSymbol.is_initialized());
    ASSERT_TRUE(!aCandlesParameters.mTimeOffsetDataSpecifier.is_initialized());
}

TEST(CandlesParametersTestSuite, SymbolOnly)
{
    CandlesParameters
            aCandlesParameters(QString("ETHBTC"), boost::none);

    ASSERT_STREQ(aCandlesParameters.mSymbol->toStdString().c_str(),
                 "ETHBTC");
    ASSERT_TRUE(!aCandlesParameters.mTimeOffsetDataSpecifier.is_initialized());
}

TEST(CandlesParametersTestSuite, SymbolAndLimit)
{
    CandlesParameters
            aCandlesParameters(
                QString("ETHBTC"),
                core::bom::TimeOffsetDataSpecifier{
                    core::bom::DataLimit(10U),
                    boost::none});

    ASSERT_STREQ(aCandlesParameters.mSymbol->toStdString().c_str(),
                 "ETHBTC");
    ASSERT_EQ(aCandlesParameters.mTimeOffsetDataSpecifier.get().mLimit.get(), 10u);
    ASSERT_TRUE(!aCandlesParameters.mTimeOffsetDataSpecifier.get().mPeriod.is_initialized());
}

TEST(CandlesParametersTestSuite, SymbolAndPeriod)
{
    CandlesParameters
            aCandlesParameters(
                QString("ETHBTC"),
                core::bom::TimeOffsetDataSpecifier{
                    boost::none,
                    QString("M30")});

    ASSERT_STREQ(aCandlesParameters.mSymbol->toStdString().c_str(),
                 "ETHBTC");
    ASSERT_TRUE(!aCandlesParameters.mTimeOffsetDataSpecifier.get().mLimit.is_initialized());
    ASSERT_STREQ(aCandlesParameters.mTimeOffsetDataSpecifier.get().mPeriod.get().toStdString().c_str(),
                "M30");
}

TEST(CandlesParametersTestSuite, AllParameters)
{
    CandlesParameters
            aCandlesParameters(
                QString("ETHBTC"),
                core::bom::TimeOffsetDataSpecifier{
                    core::bom::DataLimit(10U),
                    QString("M30")});

    ASSERT_STREQ(aCandlesParameters.mSymbol->toStdString().c_str(),
                 "ETHBTC");
    ASSERT_EQ(aCandlesParameters.mTimeOffsetDataSpecifier.get().mLimit.get(), 10u);
    ASSERT_STREQ(aCandlesParameters.mTimeOffsetDataSpecifier.get().mPeriod.get().toStdString().c_str(),
                 "M30");
}

}
}
}
}

#endif // CANDLESPARAMETERSTESTSUITE_HPP

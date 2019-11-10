#ifndef ORDERBOOKPARAMETERSTESTSUITE_HPP
#define ORDERBOOKPARAMETERSTESTSUITE_HPP

#include <gtest/gtest.h>

#include "../../../traderlib/core/bom/orderbookparameters.hpp"
#include <QDataStream>

namespace bitinvest {
namespace core {
namespace bom {
namespace test {

TEST(OrderbookParametersTestSuite, Default)
{
    OrderbookParameters aOrderbookParameters;

    ASSERT_TRUE(!aOrderbookParameters.mSymbol.is_initialized());
    ASSERT_TRUE(!aOrderbookParameters.mLimit.is_initialized());
}

TEST(OrderbookParametersTestSuite, SymbolOnly)
{
    OrderbookParameters
            aOrderbookParameters(QString("ETHBTC"), boost::none);

    ASSERT_STREQ(aOrderbookParameters.mSymbol->toStdString().c_str(),
                 "ETHBTC");
    ASSERT_TRUE(!aOrderbookParameters.mLimit.is_initialized());
}

TEST(OrderbookParametersTestSuite, SymbolAndLimit)
{
    OrderbookParameters
            aOrderbookParameters(QString("ETHBTC"), core::bom::DataLimit(10U));

    ASSERT_STREQ(aOrderbookParameters.mSymbol->toStdString().c_str(),
                 "ETHBTC");
    ASSERT_EQ(*aOrderbookParameters.mLimit, 10u);
}

}
}
}
}

#endif // ORDERBOOKPARAMETERSTESTSUITE_HPP

#ifndef TICKERSPARAMETERSTESTSUITE_HPP
#define TICKERSPARAMETERSTESTSUITE_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../traderlib/core/bom/tickersparameters.hpp"
#include <QDataStream>

namespace bitinvest {
namespace core {
namespace bom {
namespace test {

TEST(TickersParametersTestSuite, AllSymbols)
{
    TickersParameters aTickersParameters;
    ASSERT_STREQ(aTickersParameters.mSymbol.toStdString().c_str(), "");
}

TEST(TickersParametersTestSuite, SingleSymbol)
{
    TickersParameters
            aTickersParameters(QString("ETHBTC"));

    ASSERT_STREQ(aTickersParameters.mSymbol.toStdString().c_str(),
                 "ETHBTC");
}

}
}
}
}


#endif // TICKERSPARAMETERSTESTSUITE_HPP

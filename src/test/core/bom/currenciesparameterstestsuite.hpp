#ifndef CURRENCIESPARAMETERSTESTSUITE_HPP
#define CURRENCIESPARAMETERSTESTSUITE_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../traderlib/core/bom/currenciesparameters.hpp"
#include <QDataStream>

namespace bitinvest {
namespace core {
namespace bom {
namespace test {

TEST(CurrenciesParametersTestSuite, AllIds)
{
    CurrenciesParameters aCurrenciesParameters;
    ASSERT_STREQ(aCurrenciesParameters.mId.toStdString().c_str(), "");
}

TEST(CurrenciesParametersTestSuite, SingolId)
{
    CurrenciesParameters
            aCurrenciesParameters(QString("ETHBTC"));

    ASSERT_STREQ(aCurrenciesParameters.mId.toStdString().c_str(),
                 "ETHBTC");
}

}
}
}
}


#endif // CURRENCIESPARAMETERSTESTSUITE_HPP

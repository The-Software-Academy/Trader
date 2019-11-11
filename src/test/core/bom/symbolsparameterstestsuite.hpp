#ifndef SymbolsSPARAMETERSTESTSUITE_HPP
#define SymbolsSPARAMETERSTESTSUITE_HPP

#ifndef SymbolssParametersTESTSUITE_HPP
#define SymbolssParametersTESTSUITE_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../traderlib/core/bom/symbolsparameters.hpp"
#include <QDataStream>

namespace bitinvest {
namespace core {
namespace bom {
namespace test {

TEST(SymbolsParametersTestSuite, AllSymbols)
{
    SymbolsParameters aSymbolsParameters;
    ASSERT_STREQ(aSymbolsParameters.mSymbol.toStdString().c_str(), "");
}

TEST(SymbolsParametersTestSuite, SingolSymbol)
{
    SymbolsParameters
            aSymbolsParameters(QString("ETHBTC"));

    ASSERT_STREQ(aSymbolsParameters.mSymbol.toStdString().c_str(),
                 "ETHBTC");
}

}
}
}
}


#endif // SymbolssParametersTESTSUITE_HPP



#endif // SymbolsSPARAMETERSTESTSUITE_HPP

#ifndef SYMBOLSPARAMETERS_HPP
#define SYMBOLSPARAMETERS_HPP

#include <QMetaType>
#include "basictypes.h"

namespace bitinvest {
namespace core {
namespace bom {

struct SymbolsParameters
{
    SymbolsParameters():
        mSymbol(QString(""))
    {}

    SymbolsParameters(const Symbol & iSymbol):
        mSymbol(iSymbol)
    {}
    SymbolsParameters(const SymbolsParameters & other):
        mSymbol(other.mSymbol)
    {}

    const Symbol mSymbol;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::SymbolsParameters)


#endif // SYMBOLSPARAMETERS_HPP

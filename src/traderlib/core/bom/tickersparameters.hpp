#ifndef TICKERSREQUESTPARAMETERS_HPP
#define TICKERSREQUESTPARAMETERS_HPP

#include <QMetaType>
#include <QVariant>
#include "basictypes.h"

namespace bitinvest {
namespace core {
namespace bom {

struct TickersParameters
{
    TickersParameters():
        mSymbol(QString(""))
    {}
    explicit TickersParameters(const Symbol & iSymbol):
        mSymbol(iSymbol)
    {}
    TickersParameters(const TickersParameters & other):
        mSymbol(other.mSymbol)
    {}

    const Symbol mSymbol;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::TickersParameters)

#endif // TICKERSREQUESTPARAMETERS_HPP

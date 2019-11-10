#ifndef ORDERBOOKREQUESTPARAMETERS_HPP
#define ORDERBOOKREQUESTPARAMETERS_HPP


#include <boost/optional.hpp>
#include <QMetaType>
#include "basictypes.h"

namespace bitinvest {
namespace core {
namespace bom {

struct OrderbookParameters
{
    OrderbookParameters():
        mSymbol(boost::none), mLimit(boost::none)
    {}

    OrderbookParameters(const boost::optional<Symbol> & iSymbol, const boost::optional<DataLimit> &iLimit):
        mSymbol(iSymbol), mLimit(iLimit)
    {}

    OrderbookParameters(const OrderbookParameters & other):
        mSymbol(other.mSymbol), mLimit(other.mLimit)
    {}

    const boost::optional<Symbol> mSymbol;
    const boost::optional<DataLimit> mLimit;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::OrderbookParameters)

#endif // ORDERBOOKREQUESTPARAMETERS_HPP

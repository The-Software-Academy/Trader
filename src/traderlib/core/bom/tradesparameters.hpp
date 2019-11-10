#ifndef TRADESREQUESTPARAMETERS_HPP
#define TRADESREQUESTPARAMETERS_HPP

#include <QVariant>
#include <QMetaType>

#include <boost/optional.hpp>

#include "basictypes.h"

namespace bitinvest {
namespace core {
namespace bom {


struct TradesParameters
{
    TradesParameters():
        mSymbol(boost::none),
        mFilterSpecifier(boost::none),
        mDataSpecifier(boost::none)
    {}

    TradesParameters(
            const Symbol &iSymbol):
        mSymbol(iSymbol), mFilterSpecifier(boost::none), mDataSpecifier(boost::none)
    {}

    TradesParameters(
            const Symbol &iSymbol,
            const DataSpecifier& iDataSpecifier):
        mSymbol(iSymbol), mFilterSpecifier(boost::none), mDataSpecifier(iDataSpecifier)
    {}

    TradesParameters(
            const Symbol &iSymbol,
            const FilterSpecifier & iFilterSpecifier):
        mSymbol(iSymbol), mFilterSpecifier(iFilterSpecifier), mDataSpecifier(boost::none)
    {}

    TradesParameters(
            const Symbol & iSymbol,
            const FilterSpecifier & iFilterSpecifier,
            const DataSpecifier & iDataSpecifier):
        mSymbol(iSymbol), mFilterSpecifier(iFilterSpecifier), mDataSpecifier(iDataSpecifier)
    {}

    TradesParameters(const TradesParameters & other):
            mSymbol(other.mSymbol), mFilterSpecifier(other.mFilterSpecifier), mDataSpecifier(other.mDataSpecifier)
    {}


    boost::optional<Symbol> mSymbol;
    boost::optional<FilterSpecifier> mFilterSpecifier;
    boost::optional<DataSpecifier> mDataSpecifier;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::TradesParameters)
#endif // TRADESREQUESTPARAMETERS_HPP

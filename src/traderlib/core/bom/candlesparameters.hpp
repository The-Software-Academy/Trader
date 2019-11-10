#ifndef CANDLESREQUESTPARAMETERS_HPP
#define CANDLESREQUESTPARAMETERS_HPP

#include <QMetaType>
#include <QVariant>

#include "basictypes.h"

namespace bitinvest {
namespace core {
namespace bom {

struct CandlesParameters
{

    CandlesParameters():
        mSymbol(boost::none),
        mTimeOffsetDataSpecifier(boost::none)
    {}

    CandlesParameters(
            const boost::optional<Symbol> & iSymbol,
            const boost::optional<TimeOffsetDataSpecifier> & iTimeOffsetDataSpecifier):
        mSymbol(iSymbol),
        mTimeOffsetDataSpecifier(iTimeOffsetDataSpecifier)
    {}

    CandlesParameters(const CandlesParameters & other):
        mSymbol(other.mSymbol),
        mTimeOffsetDataSpecifier(other.mTimeOffsetDataSpecifier)
    {}

    ~CandlesParameters() = default;

    const boost::optional<Symbol> mSymbol;
    const boost::optional<TimeOffsetDataSpecifier> mTimeOffsetDataSpecifier;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::CandlesParameters)

#endif // CANDLESREQUESTPARAMETERS_HPP

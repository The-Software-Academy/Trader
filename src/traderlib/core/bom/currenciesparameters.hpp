#ifndef CURRENCIESPARAMETERS_HPP
#define CURRENCIESPARAMETERS_HPP

#include <QMetaType>
#include <boost/optional.hpp>
#include "basictypes.h"


namespace bitinvest {
namespace core {
namespace bom {

struct CurrenciesParameters
{
    CurrenciesParameters():
        mId("")
    {}

    CurrenciesParameters(const CurrencyId & iId):
        mId(iId)
    {}

    CurrenciesParameters(const CurrenciesParameters & other):
            mId(other.mId)
    {}

    CurrencyId mId;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::CurrenciesParameters)

#endif // CURRENCIESPARAMETERS_HPP

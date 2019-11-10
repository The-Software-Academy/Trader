#include "basictypes.h"

namespace bitinvest {
namespace core {
namespace bom {

bool operator == (const DataSpecifier & iLhs, const DataSpecifier & iRhs)
{
    return (iLhs.mLimit == iRhs.mLimit) && (iLhs.mOffset == iRhs.mOffset);
}

bool operator == (const TimeOffsetDataSpecifier & iLhs, const TimeOffsetDataSpecifier & iRhs)
{
    return (iLhs.mLimit == iRhs.mLimit) && (iLhs.mPeriod == iLhs.mPeriod);
}

bool operator == (const FilterSpecifier & iLhs, const FilterSpecifier & iRhs)
{
    return (iLhs.mBy == iRhs.mBy) && (iLhs.mFrom == iRhs.mFrom) && (iLhs.mTill == iRhs.mTill);
}

}
}
}

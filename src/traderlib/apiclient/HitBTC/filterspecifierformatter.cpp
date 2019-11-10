#include "filterspecifierformatter.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

QString FilterSpecifierFormatter::format(const core::bom::FilterSpecifier & iFilterSpecifier) const
{
    QString aStringFilterSpecifier;
    switch (iFilterSpecifier.mBy)
    {
        case bitinvest::core::bom::IntervalCriteria::TIME:
            aStringFilterSpecifier =
                    "by=timestamp&from=" +
                    boost::get<QDateTime>(iFilterSpecifier.mFrom).toString("yyyy-MM-ddThh:mm:ss.zzzZ") +
                    "&till=" +
                    boost::get<QDateTime>(iFilterSpecifier.mTill).toString("yyyy-MM-ddThh:mm:ss.zzzZ") +
                    "&";
        break;
        case bitinvest::core::bom::IntervalCriteria::OPERATION_ID:
            aStringFilterSpecifier =
                    "by=id&from=" +
                    QString::number(uint32_t{boost::get<bitinvest::core::bom::OperationId>(
                                             iFilterSpecifier.mFrom)}) +
                    "&till=" +
                    QString::number(uint32_t{boost::get<bitinvest::core::bom::OperationId>(
                                             iFilterSpecifier.mTill)}) +
                    "&";
        break;
    }
    return aStringFilterSpecifier;
}

}
}
}

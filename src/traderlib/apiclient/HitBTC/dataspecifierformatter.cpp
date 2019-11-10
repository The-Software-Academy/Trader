#include "dataspecifierformatter.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

QString DataSpecifierFormatter::format(const core::bom::DataSpecifier & iDataSpecifier) const
{
    QString aStringDataSpecifier;
    if(iDataSpecifier.mLimit.is_initialized())
    {
        aStringDataSpecifier =
                "limit=" + QString::number(uint32_t{iDataSpecifier.mLimit.get()}) + "&";
    }

    if(iDataSpecifier.mOffset.is_initialized())
    {
        aStringDataSpecifier +=
            "offset=" + QString::number(uint32_t{iDataSpecifier.mOffset.get()}) + "&";
    }
    return aStringDataSpecifier;
}

}
}
}

#ifndef DATASPECIFIERFORMATTER_HPP
#define DATASPECIFIERFORMATTER_HPP

#include "../bom/basictypes.h"

namespace bitinvest {
namespace core {
namespace apiclient {

class DataSpecifierFormatter
{
public:
    virtual QString format(const core::bom::DataSpecifier &) const = 0;
    virtual ~DataSpecifierFormatter() = default;
};

}
}
}

#endif // DATASPECIFIERFORMATTER_HPP

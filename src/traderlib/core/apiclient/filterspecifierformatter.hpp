#ifndef FILTERSPECIFIERFORMATTER_HPP
#define FILTERSPECIFIERFORMATTER_HPP

#include "../bom/basictypes.h"

namespace bitinvest {
namespace core {
namespace apiclient {

class FilterSpecifierFormatter
{
public:
    virtual QString format(const core::bom::FilterSpecifier &) const = 0;
    virtual ~FilterSpecifierFormatter() = default;
};

}
}
}

#endif // FILTERSPECIFIERFORMATTER_HPP

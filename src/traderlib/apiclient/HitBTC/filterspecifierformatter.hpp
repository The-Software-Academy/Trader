#ifndef HITBTCFILTERSPECIFIERFORMATTER_HPP
#define HITBTCFILTERSPECIFIERFORMATTER_HPP

#include <core/apiclient/filterspecifierformatter.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {


class FilterSpecifierFormatter final: public bitinvest::core::apiclient::FilterSpecifierFormatter
{
public:
    QString format(const bitinvest::core::bom::FilterSpecifier &) const;
};

}
}
}

#endif // HITBTCFILTERSPECIFIERFORMATTER_HPP

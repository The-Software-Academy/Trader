#ifndef HITBTCDATASPECIFIERFORMATTER_HPP
#define HITBTCDATASPECIFIERFORMATTER_HPP

#include<core/apiclient/dataspecifierformatter.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class DataSpecifierFormatter final: public bitinvest::core::apiclient::DataSpecifierFormatter
{
public:
    QString format(const bitinvest::core::bom::DataSpecifier &) const;
};

}
}
}

#endif // HITBTCDATASPECIFIERFORMATTER_HPP

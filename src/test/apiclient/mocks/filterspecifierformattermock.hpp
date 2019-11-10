#ifndef FILTERSPECIFIERFORMATTERMOCK_HPP
#define FILTERSPECIFIERFORMATTERMOCK_HPP

#include <core/apiclient/filterspecifierformatter.hpp>
#include <gmock/gmock.h>

namespace bitinvest {
namespace core {
namespace apiclient {
namespace test {



class FilterSpecifierFormatterMock: public apiclient::FilterSpecifierFormatter
{
public:
    MOCK_CONST_METHOD1(format, QString (const core::bom::FilterSpecifier &));
};

}
}
}
}
#endif // FILTERSPECIFIERFORMATTERMOCK_HPP

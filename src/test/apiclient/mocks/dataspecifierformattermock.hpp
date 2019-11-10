#ifndef DATASPECIFIERFORMATTERMOCK_HPP
#define DATASPECIFIERFORMATTERMOCK_HPP

#include <core/apiclient/dataspecifierformatter.hpp>
#include <gmock/gmock.h>

namespace bitinvest {
namespace core {
namespace apiclient {
namespace test {



class DataSpecifierFormatterMock: public apiclient::DataSpecifierFormatter
{
public:
    MOCK_CONST_METHOD1(format, QString (const core::bom::DataSpecifier &));
};

}
}
}
}

#endif // DATASPECIFIERFORMATTERMOCK_HPP

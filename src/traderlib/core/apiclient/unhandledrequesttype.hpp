#ifndef UNHANDLEDREQUESTTYPE_HPP
#define UNHANDLEDREQUESTTYPE_HPP

#include <exception>

namespace bitinvest {
namespace core {
namespace apiclient {

class UnhandledRequestType final: public std::invalid_argument
{
    using std::invalid_argument::invalid_argument;
};

}
}
}

#endif // UNHANDLEDREQUESTTYPE_HPP

#ifndef UNEXPECTEDPARAMETERSTYPE_HPP
#define UNEXPECTEDPARAMETERSTYPE_HPP

#include <exception>

namespace bitinvest {
namespace core {
namespace apiclient {

class UnexpectedParametersType final: public std::invalid_argument
{
    using std::invalid_argument::invalid_argument;
};

}
}
}


#endif // UNEXPECTEDPARAMETERSTYPE_HPP

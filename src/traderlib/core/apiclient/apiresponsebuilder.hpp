#ifndef APIRESPONSEBUILDER_HPP
#define APIRESPONSEBUILDER_HPP

#include<QNetworkReply>
#include<QByteArray>

#include "../bom/apiresponse.hpp"

namespace bitinvest {
namespace core {
namespace apiclient {

class ApiResponseBuilder
{
public:
    virtual ~ApiResponseBuilder() = default;
    virtual QByteArray build(const QString &) const = 0;
};

}
}
}

#endif // APIRESPONSEBUILDER_HPP

#ifndef BITINVESTRESPONSE_HPP
#define BITINVESTRESPONSE_HPP

#include<qbytearray.h>
#include<QObject>

namespace bitinvest {
namespace core {
namespace bom {

struct ApiResponse
{
    QByteArray payload;
};

}
}
}

Q_DECLARE_METATYPE(bitinvest::core::bom::ApiResponse)

#endif // BITINVESTRESPONSE_HPP

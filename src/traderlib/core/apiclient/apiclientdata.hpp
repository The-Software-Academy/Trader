#ifndef APICLIENTDATA_HPP
#define APICLIENTDATA_HPP

#include <QString>
#include <QUrl>

namespace bitinvest {
namespace core {
namespace apiclient {

class ApiClientData
{
public:
    virtual ~ApiClientData() = default;
    virtual const QString getAuthentication() const = 0;
    virtual const QUrl getApiHostAddress() const = 0;
};

}
}
}

#endif // APICLIENTDATA_HPP

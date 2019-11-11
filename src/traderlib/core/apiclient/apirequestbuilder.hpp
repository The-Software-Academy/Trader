#ifndef APIREQUESTBUILDER_HPP
#define APIREQUESTBUILDER_HPP


#include <QByteArray>
#include <QString>
#include <QSharedPointer>

#include "../bom/apirequest.hpp"
#include "unexpectedparameterstype.hpp"

namespace bitinvest {
namespace core {
namespace apiclient {


class ApiRequestBuilder
{
public:
    virtual ~ApiRequestBuilder() = default;
    virtual QString build(const core::bom::ApiRequest &) const = 0;
};

}
}
}

#endif // APIREQUESTBUILDER_HPP

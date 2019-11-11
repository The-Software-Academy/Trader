#ifndef TRADESREQUESTBUILDER_HPP
#define TRADESREQUESTBUILDER_HPP

#include "../../core/apiclient/apirequestbuilder.hpp"

namespace bitinvest {

namespace core {
namespace apiclient {
class DataSpecifierFormatter;
class FilterSpecifierFormatter;
}
}

namespace apiclient {
namespace hitbtc {

class TradesRequestBuilder : public core::apiclient::ApiRequestBuilder
{
public:
    TradesRequestBuilder(const QSharedPointer<bitinvest::core::apiclient::DataSpecifierFormatter> &,
                         const QSharedPointer<bitinvest::core::apiclient::FilterSpecifierFormatter> &);
    QString build(const core::bom::ApiRequest &) const override;

private:
    const QSharedPointer<bitinvest::core::apiclient::DataSpecifierFormatter> mDataSpecifierFormatter;
    const QSharedPointer<bitinvest::core::apiclient::FilterSpecifierFormatter> mFilterSpecifierFormatter;
};

}
}
}

#endif // TRADESREQUESTBUILDER_HPP

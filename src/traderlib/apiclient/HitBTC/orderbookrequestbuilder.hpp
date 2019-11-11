#ifndef ORDERBOOKREQUESTBUILDER_HPP
#define ORDERBOOKREQUESTBUILDER_HPP

#include "../../core/apiclient/apirequestbuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class OrderbookRequestBuilder : public core::apiclient::ApiRequestBuilder
{
public:
    OrderbookRequestBuilder();
    QString build(const core::bom::ApiRequest &) const override;
};

}
}
}

#endif // ORDERBOOKREQUESTBUILDER_HPP

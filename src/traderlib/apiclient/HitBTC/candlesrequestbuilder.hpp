#ifndef CANDLEREQUESTBUILDER_HPP
#define CANDLEREQUESTBUILDER_HPP

#include "../../core/apiclient/apirequestbuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

class CandlesRequestBuilder : public core::apiclient::ApiRequestBuilder
{
public:
    CandlesRequestBuilder();
    QString build(const core::bom::ApiRequest &) const override;
};

}
}
}

#endif // CANDLEREQUESTBUILDER_HPP

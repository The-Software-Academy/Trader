#include "balancerequestbuilder.hpp"

#include <QNetworkRequest>


namespace bitinvest {
namespace apiclient {
namespace hitbtc {

namespace {
    const QString kBalanceApiAddress("trading/balance");
}

BalanceRequestBuilder::BalanceRequestBuilder()
{}

QString BalanceRequestBuilder::build(const core::bom::ApiRequest & iRequest) const
{
    const auto & aVariant = iRequest.mParameters;
    if(!aVariant.canConvert<bitinvest::core::bom::BalanceParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                    "Unrecognized ApiParametersType expected: "
                    "bitinvest::core::bom::BalanceParameters");
    }

    return kBalanceApiAddress;
}

}
}
}

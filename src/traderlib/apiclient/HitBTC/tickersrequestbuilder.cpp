#include "tickersrequestbuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {

namespace {

const QString kTickersAddress = "public/ticker/";

}

TickersRequestBuilder::TickersRequestBuilder()
{

}

QString TickersRequestBuilder::build(const core::bom::ApiRequest & iTickersRequest) const
{
    QString aRequestString = kTickersAddress;

    const auto & aVariant = iTickersRequest.mParameters;
    if(!aVariant.canConvert<bitinvest::core::bom::TickersParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                            "Unrecognized ApiRequestParametersType expected: "
                            "bitinvest::core::bom::TickersParameters");
    }
    const auto & aTickersParameters =aVariant.value<bitinvest::core::bom::TickersParameters>();
    aRequestString += aTickersParameters.mSymbol;
    return aRequestString;
}


}
}
}

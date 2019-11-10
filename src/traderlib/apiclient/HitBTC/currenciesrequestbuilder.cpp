#include "currenciesrequestbuilder.hpp"

#include <QNetworkRequest>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

namespace {

const QString kCurrenciesAddress = "public/currency/";

}

CurrenciesRequestBuilder::CurrenciesRequestBuilder()
{

}

QString CurrenciesRequestBuilder::build(const bitinvest::core::bom::ApiRequest & iCurrenciesRequest) const
{
    QString aResultString = kCurrenciesAddress;
    const auto & aVariant = iCurrenciesRequest.mParameters;
    if(!aVariant.canConvert<core::bom::CurrenciesParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                            "Unrecognized ApiRequestParametersType expected: "
                            "core::bom::CurrenciesParameters");
    }
    const auto & aCurrenciesParameters = aVariant.value<core::bom::CurrenciesParameters>();
    aResultString += aCurrenciesParameters.mId;
    return aResultString;
}

}
}
}

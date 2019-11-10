#include "symbolsrequestbuilder.hpp"

#include <QNetworkRequest>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace  {

const QString kSymbolsAddress = "public/symbol/";

}

SymbolsRequestBuilder::SymbolsRequestBuilder()
{}

QString SymbolsRequestBuilder::build(const bitinvest::core::bom::ApiRequest & iSymbolsRequest) const
{
    QString aResultString = kSymbolsAddress;
    const auto & aVariant = iSymbolsRequest.mParameters;
    if(!aVariant.canConvert<bitinvest::core::bom::SymbolsParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                            "Unrecognized ApiRequestParametersType expected: "
                            "bitinvest::core::bom::SymbolsParameters");
    }
    const auto & aSymbolsParameters = aVariant.value<bitinvest::core::bom::SymbolsParameters>();
    aResultString += aSymbolsParameters.mSymbol;
    return aResultString;
}

}
}
}



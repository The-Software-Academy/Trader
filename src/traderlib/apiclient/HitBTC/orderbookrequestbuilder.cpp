#include "orderbookrequestbuilder.hpp"

#include <QNetworkRequest>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

namespace {
    const QString kOrderbookApiAddress = "public/orderbook/";
}

OrderbookRequestBuilder::OrderbookRequestBuilder()
{}

QString OrderbookRequestBuilder::build(const core::bom::ApiRequest &iOrderbookRequest) const
{
    const auto & aVariant = iOrderbookRequest.mParameters;
    if(!aVariant.canConvert<bitinvest::core::bom::OrderbookParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                    "Unrecognized ApiRequestParametersType expected: "
                    "bitinvest::core::bom::OrderbookParameters");
    }
    const auto & aOrderbookParameters = aVariant.value<bitinvest::core::bom::OrderbookParameters>();
    if(!aOrderbookParameters.mSymbol.is_initialized())
    {
        throw std::invalid_argument("Symbol not set in OrderbookParameters");
    }
    QString aRequestString = kOrderbookApiAddress + aOrderbookParameters.mSymbol.get() + "?";
    if(aOrderbookParameters.mLimit.is_initialized())
    {
        aRequestString += "limit=" + QString::number(aOrderbookParameters.mLimit.get()) + "&";
    }
    aRequestString.truncate(aRequestString.length() - 1);
    return aRequestString;
}

}
}
}



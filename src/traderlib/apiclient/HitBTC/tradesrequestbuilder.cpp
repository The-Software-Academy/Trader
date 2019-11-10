#include "tradesrequestbuilder.hpp"

#include <QNetworkRequest>
#include <core/apiclient/dataspecifierformatter.hpp>
#include <core/apiclient/filterspecifierformatter.hpp>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

namespace {

const QString kTradesApiAddress("public/trades/");

}

TradesRequestBuilder::TradesRequestBuilder(const QSharedPointer<bitinvest::core::apiclient::DataSpecifierFormatter> & iDataSpecifierFormatter,
                                           const QSharedPointer<bitinvest::core::apiclient::FilterSpecifierFormatter> & iFilterSpecifierFormatter):
    mDataSpecifierFormatter(iDataSpecifierFormatter), mFilterSpecifierFormatter(iFilterSpecifierFormatter)
{}

QString TradesRequestBuilder::build(const bitinvest::core::bom::ApiRequest & iTradesRequest) const
{
    auto const & aVariant = iTradesRequest.mParameters;
    if(!aVariant.canConvert<bitinvest::core::bom::TradesParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                    "Unrecognized ApiParametersType expected: "
                    "bitinvest::core::bom::TradesParameters");
    }
    const auto & aTradesParameters = aVariant.value<bitinvest::core::bom::TradesParameters>();
    if(!aTradesParameters.mSymbol.is_initialized())
    {
        throw std::invalid_argument("Symbol not set in Trades Request");
    }
    QString aRequestString = kTradesApiAddress + aTradesParameters.mSymbol.get() + "?";

    if(aTradesParameters.mDataSpecifier.is_initialized())
    {
        aRequestString += mDataSpecifierFormatter->format(aTradesParameters.mDataSpecifier.get());
    }

    if(aTradesParameters.mFilterSpecifier.is_initialized())
    {
        aRequestString += mFilterSpecifierFormatter->format(aTradesParameters.mFilterSpecifier.get());
    }

    aRequestString.truncate(aRequestString.length() - 1);
    return aRequestString;
}

}
}
}

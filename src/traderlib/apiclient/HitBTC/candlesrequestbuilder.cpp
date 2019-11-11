#include "candlesrequestbuilder.hpp"

#include <QNetworkRequest>


#include <exception>
#include <QDataStream>

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace {

const QString kCandlesApiAddress = "public/candles/";

QString formatTimeOffsetDataSpecifier(const core::bom::TimeOffsetDataSpecifier & iTimeOffsetDataSpecifier)
{
    QString aTimeOffsetDataSpecifierString;
    if(iTimeOffsetDataSpecifier.mLimit.is_initialized())
    {
        aTimeOffsetDataSpecifierString += "limit=" + QString::number(iTimeOffsetDataSpecifier.mLimit.get()) + "&";
    }
    if(iTimeOffsetDataSpecifier.mPeriod)
    {
        aTimeOffsetDataSpecifierString += "period=" + iTimeOffsetDataSpecifier.mPeriod.get() + "&";
    }
    return aTimeOffsetDataSpecifierString;
}

}

CandlesRequestBuilder::CandlesRequestBuilder()
{}

QString CandlesRequestBuilder::build(const core::bom::ApiRequest & iCandlesRequest) const
{    
    auto const & aVariant = iCandlesRequest.mParameters;
    if(!aVariant.canConvert<bitinvest::core::bom::CandlesParameters>())
    {
        throw core::apiclient::UnexpectedParametersType(
                    "Unrecognized ApiParametersType expected: "
                    "bitinvest::core::bom::CandlesParameters");
    }
    const auto & aCandlesParameters = aVariant.value<bitinvest::core::bom::CandlesParameters>();
    if(!aCandlesParameters.mSymbol.is_initialized())
    {
        throw std::invalid_argument("Symbol not set in CandlesParameters");
    }
    QString aRequestString = kCandlesApiAddress + aCandlesParameters.mSymbol.get() + "?";
    if(aCandlesParameters.mTimeOffsetDataSpecifier.is_initialized())
    {
        aRequestString += formatTimeOffsetDataSpecifier(aCandlesParameters.mTimeOffsetDataSpecifier.get());
    }
    aRequestString.truncate(aRequestString.length()-1);
    return aRequestString;
}

}
}
}


#include "hitbtcapiinitializer.hpp"

#include <core/apiclient/apitypeadaptersmap.hpp>
#include <core/apiclient/apiclientdata.hpp>

#include "balancedependenciesfactory.hpp"
#include "candlesdependenciesfactory.hpp"
#include "currenciesdependenciesfactory.hpp"
#include "orderbookdependenciesfactory.hpp"
#include "symbolsdependenciesfactory.hpp"
#include "tickersdependenciesfactory.hpp"
#include "tradesdependenciesfactory.hpp"



namespace bitinvest {
namespace apiclient {
namespace hitbtc {

namespace {
/** @warning
 * This should be read from database ** in order to not recompile
 * the library every time the apiaddress changes
**/

const QString kHitBTCApiUrl("https://api.hitbtc.com/api/2/");

/** @warning this must be moved to database for security **/
const QString kApiKey("176d7d38b0bdd7854e0cb6357d0db0a2");
const QString kSecretKey("a0186082bdc31819e7d18d2c6834fdcd");
const QString kAuthenticationString(QString("Basic ") + QString(kApiKey + ":" + kSecretKey).toLatin1().toBase64());


class HitBtcData: public core::apiclient::ApiClientData
{
public:
    const QUrl getApiHostAddress() const
    {
        return QUrl(kHitBTCApiUrl);
    }
    const QString getAuthentication() const
    {
        return kAuthenticationString;
    }

};

}

core::apiclient::ParametersTypeAdaptersMap const
HitBtcApiInitializer::getApiAdaptersMap()
{
    core::apiclient::ParametersTypeAdaptersMap kTypeAdaptersMap(
            boost::fusion::make_pair<core::bom::BalanceParameters>(
                    core::apiclient::RequestTypeHandler(new BalanceDependenciesFactory)),
            boost::fusion::make_pair<core::bom::CandlesParameters>(
                    core::apiclient::RequestTypeHandler(new CandlesDependenciesFactory)),
            boost::fusion::make_pair<core::bom::CurrenciesParameters>(
                    core::apiclient::RequestTypeHandler(new CurrenciesDependenciesFactory)),
            boost::fusion::make_pair<core::bom::OrderbookParameters>(
                    core::apiclient::RequestTypeHandler(new OrderbookDependenciesFactory)),
            boost::fusion::make_pair<core::bom::SymbolsParameters>(
                    core::apiclient::RequestTypeHandler(new SymbolsDependenciesFactory)),
            boost::fusion::make_pair<core::bom::TickersParameters>(
                    core::apiclient::RequestTypeHandler(new TickersDependenciesFactory)),
            boost::fusion::make_pair<core::bom::TradesParameters>(
                    core::apiclient::RequestTypeHandler(new TradesDependenciesFactory)));
    return kTypeAdaptersMap;
}

const QSharedPointer<const core::apiclient::ApiClientData> HitBtcApiInitializer::getClientData()
{
    return QSharedPointer<HitBtcData>::create();
}


}
}
}

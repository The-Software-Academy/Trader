#ifndef APIREQUEST_HPP
#define APIREQUEST_HPP

#include <QVariant>

#include "candlesparameters.hpp"
#include "orderbookparameters.hpp"
#include "balanceparameters.hpp"
#include "currenciesparameters.hpp"
#include "symbolsparameters.hpp"
#include "tickersparameters.hpp"
#include "tradesparameters.hpp"

namespace bitinvest {
namespace core {
namespace bom {


struct ApiRequest
{
    explicit ApiRequest(const CandlesParameters & iCandlesParameters):
        mParameters(QVariant::fromValue<CandlesParameters>(iCandlesParameters))
    {}
    explicit ApiRequest(const OrderbookParameters & iOrderbookParameters):
        mParameters(QVariant::fromValue<OrderbookParameters>(iOrderbookParameters))
    {}
    explicit ApiRequest(const BalanceParameters & iBalanceParameters):
        mParameters(QVariant::fromValue<BalanceParameters>(iBalanceParameters))
    {}
    explicit ApiRequest(const CurrenciesParameters & iCurrenciesParameters):
        mParameters(QVariant::fromValue<CurrenciesParameters>(iCurrenciesParameters))
    {}
    explicit ApiRequest(const SymbolsParameters & iSymbolsParameters):
        mParameters(QVariant::fromValue<SymbolsParameters>(iSymbolsParameters))
    {}
    explicit ApiRequest(const TickersParameters & iTickersRequestParameters):
        mParameters(QVariant::fromValue<TickersParameters>(iTickersRequestParameters))
    {}
    explicit ApiRequest(const TradesParameters & iTradesRequestParameters):
        mParameters(QVariant::fromValue<TradesParameters>(iTradesRequestParameters))
    {}

    ~ApiRequest() = default;

    const QVariant mParameters;
};

}
}
}


#endif // APIREQUEST_HPP

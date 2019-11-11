#ifndef APITYPEADAPTERSMAP_HPP
#define APITYPEADAPTERSMAP_HPP

#include <exception>

#include<QMap>

#include <boost/fusion/container/map.hpp>

#include "../bom/apirequest.hpp"
#include "apiclientusecase.hpp"



namespace bitinvest {
namespace core {
namespace apiclient {

typedef QSharedPointer<const ApiClientUsecase::DependenciesFactory> RequestTypeHandler;

typedef boost::fusion::map<
boost::fusion::pair<core::bom::BalanceParameters, RequestTypeHandler>,
boost::fusion::pair<core::bom::CandlesParameters, RequestTypeHandler>,
boost::fusion::pair<core::bom::CurrenciesParameters, RequestTypeHandler>,
boost::fusion::pair<core::bom::OrderbookParameters, RequestTypeHandler>,
boost::fusion::pair<core::bom::SymbolsParameters, RequestTypeHandler>,
boost::fusion::pair<core::bom::TickersParameters, RequestTypeHandler>,
boost::fusion::pair<core::bom::TradesParameters, RequestTypeHandler>> ParametersTypeAdaptersMap;

class ApiTypeAdaptersMap
{
public:
    ApiTypeAdaptersMap(const ParametersTypeAdaptersMap & iTypeAdaptersMap):
        mTypeAdaptersMap(iTypeAdaptersMap)
    {}

    RequestTypeHandler getAdapters(const core::bom::ApiRequest & iRequest) const;

private:
    const ParametersTypeAdaptersMap mTypeAdaptersMap;

};

}
}
}

#endif // APITYPEADAPTERSMAP_HPP

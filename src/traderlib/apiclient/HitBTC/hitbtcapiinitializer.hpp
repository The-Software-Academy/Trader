#ifndef HITBTCAPIDATA_HPP
#define HITBTCAPIDATA_HPP

#include <QUrl>
#include<core/apiclient/apitypeadaptersmap.hpp>

namespace bitinvest {

namespace core {
namespace apiclient {
class ApiClientData;
}
}

namespace apiclient {
namespace hitbtc {

/** @todo This class should be evolved:
 * - retrieve data from db
 * - add an interface to inject it in the client
 * - splitted
 * */

struct HitBtcApiInitializer
{
    static  const core::apiclient::ParametersTypeAdaptersMap
    getApiAdaptersMap();
    static const QSharedPointer<const core::apiclient::ApiClientData>
    getClientData();
};

}
}
}

#endif // HITBTCAPIDATA_HPP

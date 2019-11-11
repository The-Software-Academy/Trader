#include "currenciesresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

CurrenciesResponseBuilder::CurrenciesResponseBuilder()
{

}

QByteArray CurrenciesResponseBuilder::build(const QString & iRawResponse) const
{
    return iRawResponse.toLatin1();
}

}
}
}

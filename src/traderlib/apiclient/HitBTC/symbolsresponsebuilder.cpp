#include "symbolsresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

SymbolsResponseBuilder::SymbolsResponseBuilder()
{

}

QByteArray SymbolsResponseBuilder::build(const QString & iRawResponse) const
{
    return iRawResponse.toLatin1();
}

}
}
}

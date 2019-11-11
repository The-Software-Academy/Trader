#include "tradesresponsebuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {

TradesResponseBuilder::TradesResponseBuilder()
{

}

QByteArray TradesResponseBuilder::build(const QString & iReply) const
{
    return iReply.toLatin1();
}

}
}
}


#include "orderbookresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {


OrderbookResponseBuilder::OrderbookResponseBuilder()
{

}

QByteArray OrderbookResponseBuilder::build(const QString & iReply) const
{
    return iReply.toLatin1();
}

}
}
}

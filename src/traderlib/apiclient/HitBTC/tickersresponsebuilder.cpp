#include "tickersresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

TickersResponseBuilder::TickersResponseBuilder()
{

}

QByteArray TickersResponseBuilder::build(const QString& iReplyData) const
{
    return iReplyData.toLatin1();
}

}
}
}

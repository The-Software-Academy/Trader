#include "candlesresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {

CandlesResponseBuilder::CandlesResponseBuilder()
{

}

QByteArray CandlesResponseBuilder::build(QString const& iReply) const
{
    return iReply.toLatin1();
}

}
}
}

#include "balanceresponsebuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {


BalanceResponseBuilder::BalanceResponseBuilder()
{

}

QByteArray BalanceResponseBuilder::build(const QString& iReplyData) const
{
    return iReplyData.toLatin1();
}

}
}
}


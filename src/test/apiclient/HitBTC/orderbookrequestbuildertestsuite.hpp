#ifndef ORDERBOOKREQUESTBUILDERTESTSUITE_HPP
#define ORDERBOOKREQUESTBUILDERTESTSUITE_HPP

#include <gtest/gtest.h>
#include "../../../traderlib/apiclient/HitBTC/orderbookrequestbuilder.hpp"


namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

TEST(OrderbookRequestBuilderTestSuite, EmptyRequest)
{
    core::bom::ApiRequest aRequest(core::bom::OrderbookParameters{});
    ASSERT_ANY_THROW(OrderbookRequestBuilder().build(aRequest));
}

TEST(OrderbookRequestBuilderTestSuite, WrongParametersType)
{
    core::bom::ApiRequest aRequest(core::bom::TradesParameters{});
    ASSERT_THROW(OrderbookRequestBuilder().build(aRequest), core::apiclient::UnexpectedParametersType);
}

TEST(OrderbookRequestBuilderTestSuite, SymbolOnly)
{
    core::bom::ApiRequest aRequest(bitinvest::core::bom::OrderbookParameters(
                            QString("ETHBTC"),
                            boost::none));
    ASSERT_STREQ(OrderbookRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/orderbook/ETHBTC");
}

TEST(OrderbookRequestBuilderTestSuite, SymbolAndLimit)
{
    core::bom::ApiRequest aRequest(bitinvest::core::bom::OrderbookParameters(
                            QString("ETHBTC"),
                            static_cast<core::bom::DataLimit>(0U)));
    ASSERT_STREQ(OrderbookRequestBuilder().build(aRequest).toStdString().c_str(),
                 "public/orderbook/ETHBTC?limit=0");
}

}
}
}
}

#endif // ORDERBOOKREQUESTBUILDERTESTSUITE_HPP

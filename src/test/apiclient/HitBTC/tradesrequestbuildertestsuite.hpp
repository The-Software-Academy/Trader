#ifndef TRADESREQUESTBUILDERTESTSUITE_HPP
#define TRADESREQUESTBUILDERTESTSUITE_HPP

#include <gtest/gtest.h>
#include "../mocks/dataspecifierformattermock.hpp"
#include "../mocks/filterspecifierformattermock.hpp"

#include "../../../traderlib/apiclient/HitBTC/tradesrequestbuilder.hpp"

namespace bitinvest {
namespace apiclient {
namespace hitbtc {
namespace test {

class TradesRequestBuilderTestSuite: public ::testing::Test
{
public:
    TradesRequestBuilderTestSuite():
        mMockDataFormatter(QSharedPointer<::testing::StrictMock<bitinvest::core::apiclient::test::DataSpecifierFormatterMock>>::create()),
        mMockFilterFormatter(QSharedPointer<::testing::StrictMock<bitinvest::core::apiclient::test::FilterSpecifierFormatterMock>>::create()),
        mTradesRequestBuilder(mMockDataFormatter, mMockFilterFormatter)
    {}
    QSharedPointer<bitinvest::core::apiclient::test::DataSpecifierFormatterMock> mMockDataFormatter;
    QSharedPointer<bitinvest::core::apiclient::test::FilterSpecifierFormatterMock> mMockFilterFormatter;
    TradesRequestBuilder mTradesRequestBuilder;
};

TEST_F(TradesRequestBuilderTestSuite, InvalidArgument)
{
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{});
    ASSERT_THROW(mTradesRequestBuilder.build(aRequest),
                 std::invalid_argument);
}

TEST_F(TradesRequestBuilderTestSuite, UnrecognizedRequestParameters)
{
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TickersParameters{});
    ASSERT_THROW(mTradesRequestBuilder.build(aRequest),
                 core::apiclient::UnexpectedParametersType);
}

TEST_F(TradesRequestBuilderTestSuite, SymbolOnly)
{
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{
                                                  bitinvest::core::bom::Symbol("ETHBTC")});
    ASSERT_STREQ(mTradesRequestBuilder.build(aRequest).toStdString().c_str(),
                 "public/trades/ETHBTC");
}

TEST_F(TradesRequestBuilderTestSuite, SymbolAndFullDataSpecifier)
{
    bitinvest::core::bom::DataSpecifier aDataSpecifier{
            bitinvest::core::bom::DataLimit{1000},
            bitinvest::core::bom::DataOffset{2}};
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{
                                                  bitinvest::core::bom::Symbol("ETHBTC"),
                                                  aDataSpecifier
                                              });
    EXPECT_CALL(*mMockDataFormatter.data(), format(aDataSpecifier)).WillOnce(
                ::testing::Return(QString("limit=1000&offset=2&")));
    ASSERT_STREQ(mTradesRequestBuilder.build(aRequest).toStdString().c_str(),
                 "public/trades/ETHBTC?limit=1000&offset=2");

}

TEST_F(TradesRequestBuilderTestSuite, SymbolAndDataLimit)
{
    bitinvest::core::bom::DataSpecifier aDataSpecifier{
                                  bitinvest::core::bom::DataLimit{1000},
                                  boost::none};
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{
                                                  bitinvest::core::bom::Symbol("ETHBTC"),
                                                  aDataSpecifier
                                              });
    EXPECT_CALL(*mMockDataFormatter.data(), format(aDataSpecifier)).WillOnce(
                ::testing::Return(QString("limit=1000&")));
    ASSERT_STREQ(mTradesRequestBuilder.build(aRequest).toStdString().c_str(),
                 "public/trades/ETHBTC?limit=1000");

}

TEST_F(TradesRequestBuilderTestSuite, SymbolAndOffset)
{
    bitinvest::core::bom::DataSpecifier aDataSpecifier{
        boost::none,
        bitinvest::core::bom::DataOffset{2}};
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{
                                                  bitinvest::core::bom::Symbol("ETHBTC"),
                                                  aDataSpecifier
                                              });
    EXPECT_CALL(*mMockDataFormatter.data(), format(aDataSpecifier)).WillOnce(
                ::testing::Return(QString("offset=2&")));
    ASSERT_STREQ(mTradesRequestBuilder.build(aRequest).toStdString().c_str(),
                 "public/trades/ETHBTC?offset=2");

}

TEST_F(TradesRequestBuilderTestSuite, SymbolAndFilterSpecifierTime)
{
    QDateTime startingDate{
        QDateTime::fromString("2017-04-14T12:18:40.426Z", "yyyy-MM-ddThh:mm:ss.zzzZ")
    };
    QDateTime endDate{
        QDateTime::fromString("2017-04-14T12:18:50.426Z", "yyyy-MM-ddThh:mm:ss.zzzZ")
    };
    bitinvest::core::bom::FilterSpecifier aFilterSpecifier(
      startingDate,
      endDate);
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{
                                                  bitinvest::core::bom::Symbol("ETHBTC"),
                                                  aFilterSpecifier
                                              });
    EXPECT_CALL(*mMockFilterFormatter.data(), format(aFilterSpecifier)).
            WillOnce(::testing::Return(QString("by=timestamp&from=2017-04-14T12:18:40.426Z&till=2017-04-14T12:18:50.426Z&")));
    ASSERT_STREQ(mTradesRequestBuilder.build(aRequest).toStdString().c_str(),
                 "public/trades/ETHBTC?by=timestamp&from=2017-04-14T12:18:40.426Z&till=2017-04-14T12:18:50.426Z");

}

TEST_F(TradesRequestBuilderTestSuite, SymbolAndFilterSpecifierId)
{
    bitinvest::core::bom::FilterSpecifier aFilterSpecifier(
      bitinvest::core::bom::OperationId{39956},
      bitinvest::core::bom::OperationId{45577});
    bitinvest::core::bom::ApiRequest aRequest(bitinvest::core::bom::TradesParameters{
                                                  bitinvest::core::bom::Symbol("ETHBTC"),
                                                  aFilterSpecifier
                                              });
    EXPECT_CALL(*mMockFilterFormatter.data(), format(aFilterSpecifier)).
            WillOnce(::testing::Return(QString("by=id&from=39956&till=45577&")));
    ASSERT_STREQ(mTradesRequestBuilder.build(aRequest).toStdString().c_str(),
                 "public/trades/ETHBTC?by=id&from=39956&till=45577");
}

}
}
}
}

#endif // TRADESREQUESTBUILDERTESTSUITE_HPP

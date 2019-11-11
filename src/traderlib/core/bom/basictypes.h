#ifndef BASICTYPES_H
#define BASICTYPES_H

#include <QString>
#include <QDateTime>

#include <boost/optional.hpp>
#include <boost/variant.hpp>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include <boost/serialization/strong_typedef.hpp>
#pragma GCC diagnostic pop
namespace bitinvest {
namespace core {
namespace bom {

enum class Ordering {
    ASC,
    DESC
};

enum class IntervalCriteria {
    TIME,
    OPERATION_ID
};

typedef QString Symbol;
typedef QString CurrencyId;
BOOST_STRONG_TYPEDEF(uint32_t, OperationId)
typedef boost::variant<QDateTime, OperationId> DataBound;
BOOST_STRONG_TYPEDEF(uint32_t, DataLimit)
BOOST_STRONG_TYPEDEF(uint32_t, DataOffset)
typedef QString TimeOffset;
typedef double Price;

struct DataSpecifier
{
    boost::optional<DataLimit> mLimit;
    boost::optional<DataOffset> mOffset;
};

struct TimeOffsetDataSpecifier
{
    boost::optional<DataLimit> mLimit;
    boost::optional<TimeOffset> mPeriod;
};

struct FilterSpecifier
{
    FilterSpecifier(const QDateTime & iFrom, const QDateTime & iTill):
        mBy(IntervalCriteria::TIME), mFrom(iFrom), mTill(iTill)
    {}

    FilterSpecifier(const OperationId & iFrom, const OperationId & iTill):
        mBy(IntervalCriteria::OPERATION_ID), mFrom(iFrom), mTill(iTill)
    {}
    IntervalCriteria mBy;
    DataBound mFrom;
    DataBound mTill;
};

bool operator == (const DataSpecifier &, const DataSpecifier &);
bool operator == (const TimeOffsetDataSpecifier &, const TimeOffsetDataSpecifier &);
bool operator == (const FilterSpecifier & , const FilterSpecifier &);


}
}
}


#endif // BASICTYPES_H

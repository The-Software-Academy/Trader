#include "apitypeadaptersmap.hpp"

#include <boost/fusion/sequence/intrinsic/at_key.hpp>
#include <boost/fusion/include/at_key.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/iterator/key_of.hpp>
#include <boost/fusion/include/key_of.hpp>

#include "unhandledrequesttype.hpp"

namespace bitinvest {
namespace core {
namespace apiclient {

namespace {

thread_local RequestTypeHandler gDispatcherResult;


struct TypeBasedAdaptersDispatcher
{
    TypeBasedAdaptersDispatcher(const QVariant & iVariant):
        mQuery(iVariant)
    {}
    template<typename T>
    void operator()(const T & Pair) const
    {
        if(mQuery.canConvert<typename boost::fusion::result_of::first<T>::type>())
        {
            gDispatcherResult = Pair.second;
        }
    }
    const QVariant&  mQuery;
};

}

RequestTypeHandler ApiTypeAdaptersMap::getAdapters(const core::bom::ApiRequest & iRequest) const
{
    gDispatcherResult = nullptr;
    TypeBasedAdaptersDispatcher aDispatcher(iRequest.mParameters);
    boost::fusion::for_each(mTypeAdaptersMap, aDispatcher);
    if(!gDispatcherResult)
    {
        throw UnhandledRequestType("Request does not match any known parameter type");
    }
    return gDispatcherResult;
}


}
}
}

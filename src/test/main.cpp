#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "apiclient/HitBTC/balancerequestbuildertestsuite.hpp"
#include "apiclient/HitBTC/candlesrequestbuildertestsuite.hpp"
#include "apiclient/HitBTC/orderbookrequestbuildertestsuite.hpp"
#include "apiclient/HitBTC/tradesrequestbuildertestsuite.hpp"
#include "core/bom/orderbookparameterstestsuite.hpp"
#include "core/bom/candlesparameterstestsuite.hpp"
#include "core/bom/tickersparameterstestsuite.hpp"
#include "core/bom/symbolsparameterstestsuite.hpp"
#include "core/bom/currenciesparameterstestsuite.hpp"
#include "apiclient/HitBTC/currenciesrequestbuildertestsuite.hpp"
#include "apiclient/HitBTC/symbolsrequestbuildertestsuite.hpp"
#include "apiclient/HitBTC/balancedependenciesfactorytestsuite.hpp"
#include "apiclient/HitBTC/tradesresponsebuildertestsuite.hpp"
#include "apiclient/HitBTC/candlesdependenciesfactorytestsuite.hpp"
#include "apiclient/HitBTC/currenciesdependenciesfactorytestsuite.hpp"
#include "apiclient/HitBTC/orderbookdependenciesfactorytestsuite.hpp"
#include "apiclient/HitBTC/symbolsdependenciesfactorytestsuite.hpp"
#include "apiclient/HitBTC/tickersrequestbuildertestsuite.hpp"
#include "apiclient/HitBTC/tickersdependenciesfactorytestsuite.hpp"
#include "apiclient/HitBTC/tradesdependenciesfactorytestsuite.hpp"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

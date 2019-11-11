include(gtest_dependency.pri)

TEMPLATE = app

QT += testlib network
QT -= gui

CONFIG += c++11 console thread
CONFIG -= app_bundle

INCLUDEPATH += $$PWD/../traderlib/
DEPENDPATH += $$PWD/../traderlib/
LIBS += -L$$OUT_PWD/../traderlib/ -ltrader
PRE_TARGETDEPS += $$OUT_PWD/../traderlib/libtrader.a
QMAKE_CFLAGS_DEBUG += -fprofile-arcs -ftest-coverage
QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage
QMAKE_LFLAGS_DEBUG += -lgcov --coverage

TARGET = test

SOURCES += main.cpp

HEADERS = \
    apiclient/HitBTC/balancerequestbuildertestsuite.hpp \
    apiclient/HitBTC/candlesrequestbuildertestsuite.hpp \
    apiclient/HitBTC/orderbookrequestbuildertestsuite.hpp \
    apiclient/HitBTC/tradesrequestbuildertestsuite.hpp \
    core/bom/orderbookparameterstestsuite.hpp \
    core/bom/candlesparameterstestsuite.hpp \
    core/bom/tickersparameterstestsuite.hpp \
    core/bom/symbolsparameterstestsuite.hpp \
    core/bom/currenciesparameterstestsuite.hpp \
    apiclient/mocks/apirequestmock.hpp \
    apiclient/HitBTC/currenciesrequestbuildertestsuite.hpp \
    apiclient/HitBTC/symbolsrequestbuildertestsuite.hpp \
    apiclient/HitBTC/balancedependenciesfactorytestsuite.hpp \
    apiclient/HitBTC/tradesresponsebuildertestsuite.hpp \
    apiclient/mocks/dataspecifierformattermock.hpp \
    apiclient/mocks/filterspecifierformattermock.hpp \
    apiclient/HitBTC/candlesdependenciesfactorytestsuite.hpp \
    apiclient/HitBTC/currenciesdependenciesfactorytestsuite.hpp \
    apiclient/HitBTC/orderbookdependenciesfactorytestsuite.hpp \
    apiclient/HitBTC/symbolsdependenciesfactorytestsuite.hpp \
    apiclient/HitBTC/tickersrequestbuildertestsuite.hpp \
    apiclient/HitBTC/tickersdependenciesfactorytestsuite.hpp \
    apiclient/HitBTC/tradesdependenciesfactorytestsuite.hpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

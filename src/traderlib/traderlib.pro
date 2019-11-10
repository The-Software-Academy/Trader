#-------------------------------------------------
#
# Project created by QtCreator 2018-01-28T15:12:14
#
#-------------------------------------------------

QT       += network sql

QT       -= gui

TARGET = traderlib
TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11
TARGET = trader
QMAKE_CXXFLAGS_DEBUG += -Wall -fprofile-arcs -ftest-coverage

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/apiclient/apiconversation.cpp \
    apiclient/HitBTC/balancerequestbuilder.cpp \
    apiclient/HitBTC/balanceresponsebuilder.cpp \
    apiclient/HitBTC/candlesrequestbuilder.cpp \
    apiclient/HitBTC/candlesresponsebuilder.cpp \
    apiclient/HitBTC/orderbookrequestbuilder.cpp \
    apiclient/HitBTC/tradesrequestbuilder.cpp \
    apiclient/HitBTC/orderbookresponsebuilder.cpp \
    apiclient/HitBTC/tradesresponsebuilder.cpp \
    apiclient/HitBTC/symbolsrequestbuilder.cpp \
    apiclient/HitBTC/currenciesrequestbuilder.cpp \
    core/apiclient/apitypeadaptersmap.cpp \
    apiclient/HitBTC/currenciesresponsebuilder.cpp \
    apiclient/HitBTC/symbolsresponsebuilder.cpp \
    apiclient/HitBTC/tickersrequestbuilder.cpp \
    apiclient/HitBTC/tickersresponsebuilder.cpp \
    apiclient/HitBTC/hitbtcapiinitializer.cpp \
    core/apiclient/apiclientusecase.cpp \
    core/apiclient/apiclient.cpp \
    apiclient/HitBTC/balancedependenciesfactory.cpp \
    apiclient/HitBTC/candlesdependenciesfactory.cpp \
    apiclient/HitBTC/currenciesdependenciesfactory.cpp \
    apiclient/HitBTC/orderbookdependenciesfactory.cpp \
    apiclient/HitBTC/symbolsdependenciesfactory.cpp \
    apiclient/HitBTC/tickersdependenciesfactory.cpp \
    apiclient/HitBTC/tradesdependenciesfactory.cpp \
    apiclient/HitBTC/dataspecifierformatter.cpp \
    apiclient/HitBTC/filterspecifierformatter.cpp \
    core/bom/basictypes.cpp


HEADERS += \
    core/bom/apiresponse.hpp \
    core/bom/apierror.hpp \
    core/apiclient/apirequestbuilder.hpp \
    core/apiclient/apiresponsebuilder.hpp \
    core/apiclient/apitypeadaptersmap.hpp \
    core/apiclient/apiconversation.hpp \
    apiclient/HitBTC/balancerequestbuilder.hpp \
    apiclient/HitBTC/balanceresponsebuilder.hpp \
    apiclient/HitBTC/candlesrequestbuilder.hpp \
    apiclient/HitBTC/candlesresponsebuilder.hpp \
    apiclient/HitBTC/orderbookrequestbuilder.hpp \
    apiclient/HitBTC/tradesrequestbuilder.hpp \
    apiclient/HitBTC/orderbookresponsebuilder.hpp \
    apiclient/HitBTC/tradesresponsebuilder.hpp \
    apiclient/HitBTC/symbolsrequestbuilder.hpp \
    apiclient/HitBTC/currenciesrequestbuilder.hpp \
    core/bom/symbolsparameters.hpp \
    core/bom/currenciesparameters.hpp \
    core/bom/apirequest.hpp \
    apiclient/HitBTC/currenciesresponsebuilder.hpp \
    apiclient/HitBTC/symbolsresponsebuilder.hpp \
    core/bom/balanceparameters.hpp \
    core/bom/candlesparameters.hpp \
    core/bom/orderbookparameters.hpp \
    core/bom/tickersparameters.hpp \
    core/bom/tradesparameters.hpp \
    apiclient/HitBTC/tickersresponsebuilder.hpp \
    apiclient/HitBTC/tickersrequestbuilder.hpp \
    core/bom/basictypes.h \
    apiclient/HitBTC/hitbtcapiinitializer.hpp \
    core/apiclient/apiclientusecase.hpp \
    core/apiclient/apiclientdata.hpp \
    core/apiclient/apiclient.hpp \
    apiclient/HitBTC/balancedependenciesfactory.hpp \
    apiclient/HitBTC/candlesdependenciesfactory.hpp \
    apiclient/HitBTC/currenciesdependenciesfactory.hpp \
    apiclient/HitBTC/orderbookdependenciesfactory.hpp \
    apiclient/HitBTC/symbolsdependenciesfactory.hpp \
    apiclient/HitBTC/tickersdependenciesfactory.hpp \
    apiclient/HitBTC/tradesdependenciesfactory.hpp \
    core/apiclient/unhandledrequesttype.hpp \
    core/apiclient/unexpectedparameterstype.hpp \
    apiclient/HitBTC/dataspecifierformatter.hpp \
    core/apiclient/filterspecifierformatter.hpp \
    apiclient/HitBTC/filterspecifierformatter.hpp \
    core/apiclient/dataspecifierformatter.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    indiv_graph.cpp \
    individual_vertex.cpp \
    int_edge.cpp


include(sado.pri)
include(../gausser/gausser.pri)


# C++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -std=c++14
# -Weffc++ goes bad with Qt
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic

#Boost.Graph
LIBS += -lboost_graph
include(../BoostGraphTutorial/BoostGraphTutorial/boost_graph_tutorial.pri)

HEADERS += \
    indiv_graph.h \
    individual_vertex.h \
    int_edge.h

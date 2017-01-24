include(any_test_qtcore.pri)
include(sado.pri)
include(sado_test.pri)
include(../gausser/gausser.pri)

# Boost.Graph
include(../BoostGraphTutorial/BoostGraphTutorial/boost_graph_tutorial.pri)
LIBS += -lboost_graph

SOURCES += sado_main_test.cpp


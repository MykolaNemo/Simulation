QT += widgets
CONFIG += c++17
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

BOOST_VERSION=1_68

INCLUDEPATH+=boost/$${BOOST_VERSION}/include

win32{
QMAKE_CXXFLAGS+=/std:c++17
release:LIBS+=-Lboost/$${BOOST_VERSION}/lib/win/x64/release
debug:LIBS+=-Lboost/$${BOOST_VERSION}/lib/win/x64/debug
}

unix{
QMAKE_CXXFLAGS+=-std=c++17
LIBS+=-Lboost/$${BOOST_VERSION}/lib/linux
QMAKE_RPATHDIR += /usr/local/gcc-8.2/lib64
}

SOURCES += \
        main.cpp \
    scene.cpp \
    behaviours/sheepbehaviour.cpp \
    BTNodes/leafnodes/eatfoodaction.cpp \
    BTNodes/leafnodes/gotofoodaction.cpp \
    BTNodes/leafnodes/idleaction.cpp \
    BTNodes/leafnodes/ishungrycheck.cpp \
    BTNodes/leafnodes/nearfoodcheck.cpp \
    BTNodes/behaviourtree.cpp \
    BTNodes/fallback.cpp \
    BTNodes/invertor.cpp \
    BTNodes/sequence.cpp \
    datastruct/binarysearchtree.cpp \
    graphicsitems/grassgraphicsitem.cpp \
    graphicsitems/sheepgraphicsitem.cpp \
    models/animal/animal.cpp \
    models/animal/sheep.cpp \
    models/plant/grass.cpp \
    models/plant/plant.cpp \
    models/field.cpp \
    models/fieldobject.cpp \
    fieldview.cpp \
    simcore.cpp \
    ECS/Systems/graphicssystem.cpp \
    ECS/Systems/aisystem.cpp \
    ECS/entity.cpp \
    ECS/ecsengine.cpp

HEADERS += \
    position.h \
    size2d.h \
    signal.h \
    scene.h \
    virtual_enable_shared_from_this.h \
    behaviours/blackboards/blackboard.h \
    behaviours/sheepbehaviour.h \
    BTNodes/leafnodes/eatfoodaction.h \
    BTNodes/leafnodes/gotofoodaction.h \
    BTNodes/leafnodes/idleaction.h \
    BTNodes/leafnodes/ishungrycheck.h \
    BTNodes/leafnodes/nearfoodcheck.h \
    BTNodes/behaviourtree.h \
    BTNodes/fallback.h \
    BTNodes/invertor.h \
    BTNodes/sequence.h \
    datastruct/binarysearchtree.h \
    graphicsitems/grassgraphicsitem.h \
    graphicsitems/sheepgraphicsitem.h \
    models/animal/animal.h \
    models/animal/sheep.h \
    models/plant/grass.h \
    models/plant/plant.h \
    models/field.h \
    models/fieldobject.h \
    fieldview.h \
    position.h \
    signal.h \
    simcore.h \
    size2d.h \
    virtual_enable_shared_from_this.h \
    ECS/component.h \
    ECS/entity.h \
    ECS/Components/graphicscomponent.h \
    ECS/Components/hungercomponent.h \
    ECS/system.h \
    ECS/Systems/graphicssystem.h \
    ECS/Components/positioncomponent.h \
    ECS/Components/velocitycomponent.h \
    ECS/Systems/aisystem.h \
    ECS/Components/aicomponent.h \
    behaviours/behaviour.h \
    ECS/ecsengine.h \
    ECS/Components/foodcomponent.h \
    ECS/Components/canbeoccupiedcomponent.h

SUBDIRS += \
    Sim.pro

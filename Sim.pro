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

win32{
QMAKE_CXXFLAGS+=/std:c++17
INCLUDEPATH+=boost/$${BOOST_VERSION}/win/include
release:LIBS+=-Lboost/$${BOOST_VERSION}/win/lib/x64/release
debug:LIBS+=-Lboost/$${BOOST_VERSION}/win/lib/x64/debug
}

unix{
QMAKE_CXXFLAGS+=-std=c++17
INCLUDEPATH+=boost/$${BOOST_VERSION}/include
# -L     -> buildtime linker search paths
# -rpath -> runtime linker paths and libraries
# -Wl    -> comma separated values
LIBS+=-Lboost/$${BOOST_VERSION}/linux/lib
LIBS+=-Wl,-rpath=-L/usr/local/gcc-8.2/lib64
}

SOURCES += \
        main.cpp \
    fieldview.cpp \
    simcore.cpp \
    scene.cpp \
    models/field.cpp \
    models/fieldobject.cpp \
    models/animal/animal.cpp \
    models/animal/sheep.cpp \
    models/plant/plant.cpp \
    models/plant/grass.cpp \
    state/animalstates/animalstatewalking.cpp \
    state/animalstates/animalstateidle.cpp \
    state/animalstates/animalstateeating.cpp \
    state/plantstates/plantstategrowing.cpp \
    state/plantstates/plantstatenotgrowing.cpp \
    graphicsitems/sheepgraphicsitem.cpp \
    graphicsitems/grassgraphicsitem.cpp \
    datastruct/binarysearchtree.cpp

HEADERS += \
    position.h \
    size2d.h \
    fieldview.h \
    simcore.h \
    signal.h \
    scene.h \
    models/animal/animal.h \
    models/animal/sheep.h \
    models/field.h \
    models/fieldobject.h \
    models/plant/plant.h \
    models/plant/grass.h \
    state/state.h \
    state/animalstates/animalstatewalking.h \
    state/animalstates/animalstateidle.h \
    state/animalstates/animalstateeating.h \
    state/plantstates/plantstategrowing.h \
    state/plantstates/plantstatenotgrowing.h \
    graphicsitems/sheepgraphicsitem.h \
    graphicsitems/grassgraphicsitem.h \
    datastruct/binarysearchtree.h

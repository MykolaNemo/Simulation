QT += widgets
CONFIG += c++17
CONFIG -= app_bundle

QMAKE_CXXFLAGS += /std:c++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += boost_1_67_0

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
    visitors/drawervisitor.cpp \
    state/animalstates/animalstatewalking.cpp \
    state/animalstates/animalstateidle.cpp \
    state/animalstates/animalstateeating.cpp \
    state/plantstates/plantstategrowing.cpp \
    state/plantstates/plantstatenotgrowing.cpp

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
    visitors/drawervisitor.h \
    state/state.h \
    state/animalstates/animalstatewalking.h \
    state/animalstates/animalstateidle.h \
    state/animalstates/animalstateeating.h \
    state/plantstates/plantstategrowing.h \
    state/plantstates/plantstatenotgrowing.h \
    canbedrawn.h

#-------------------------------------------------
#
# Project created by QtCreator 2018-11-26T13:52:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BehaviourTree
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    BehaviourNodes/behaviourtree.cpp \
    BehaviourNodes/sequence.cpp \
    BehaviourNodes/leaf.cpp \
    BehaviourNodes/invertor.cpp \
    BehaviourNodes/repeater.cpp \
    NodeLabels/nodelabel.cpp \
    graphicsview/graphicsview.cpp \
    NodeLabels/sequencenodelabel.cpp \
    NodeLabels/fallbacknodelabel.cpp \
    NodeGraphicsItems/sequencegraphicsitem.cpp \
    NodeGraphicsItems/fallbackgraphicsitem.cpp \
    NodeGraphicsItems/nodegraphicsitem.cpp \
    GraphicsItems/arrowitem.cpp \
    GraphicsItems/anchoritem.cpp \
    graphicsscene.cpp \
    graphicsview/graphicsviewnormalmode.cpp \
    graphicsview/graphicsviewabstractmode.cpp \
    graphicsview/graphicsviewarrowplacemode.cpp \
    NodeLabels/rootnodelabel.cpp \
    NodeGraphicsItems/rootgraphicsitem.cpp \
    BehaviourNodes/tickgenerator.cpp \
    BehaviourNodes/fallback.cpp \
    NodeLabels/leafnodelabel.cpp \
    NodeGraphicsItems/leafgraphicsitem.cpp

HEADERS += \
        mainwindow.h \
    BehaviourNodes/behaviourtree.h \
    BehaviourNodes/sequence.h \
    BehaviourNodes/leaf.h \
    BehaviourNodes/invertor.h \
    BehaviourNodes/repeater.h \
    NodeLabels/nodelabel.h \
    graphicsview/graphicsview.h \
    NodeLabels/sequencenodelabel.h \
    NodeLabels/fallbacknodelabel.h \
    NodeGraphicsItems/sequencegraphicsitem.h \
    NodeGraphicsItems/fallbackgraphicsitem.h \
    NodeGraphicsItems/nodegraphicsitem.h \
    GraphicsItems/arrowitem.h \
    GraphicsItems/anchoritem.h \
    graphicsscene.h \
    graphicsview/graphicsviewnormalmode.h \
    graphicsview/graphicsviewabstractmode.h \
    graphicsview/graphicsviewarrowplacemode.h \
    NodeLabels/rootnodelabel.h \
    NodeGraphicsItems/rootgraphicsitem.h \
    tree.h \
    BehaviourNodes/tickgenerator.h \
    BehaviourNodes/fallback.h \
    NodeLabels/leafnodelabel.h \
    NodeGraphicsItems/leafgraphicsitem.h \
    sheep.h

FORMS += \
        mainwindow.ui

unix{
QMAKE_CXXFLAGS+=-std=c++17
QMAKE_RPATHDIR += /usr/local/gcc-8.2/lib64
}

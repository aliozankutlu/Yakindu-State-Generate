TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Statechart.c \
    Statechart3.c \
    control.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sc_types.h \
    Statechart.h \
    Statechart_required.h \
    Statechart3.h \
    control.h


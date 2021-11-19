TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Statechart.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sc_types.h \
    Statechart.h \
    Statechart_required.h


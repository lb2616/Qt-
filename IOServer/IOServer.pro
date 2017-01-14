TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    data_server.c \
    logic_server.c \
    server.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    server.h \
    data_server.h \
    logic_server.h \

DISTFILES += \
    dat/login_table.dat \
    dat/register_info.dat \
    dat/register_info.txt


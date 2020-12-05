QT       += core gui widgets
TARGET = Plugin1
TEMPLATE = lib
CONFIG += c++11 plugin





HEADERS += \
    pluginone.h

SOURCES += \
    pluginone.cpp

DISTFILES += \
    pluginone.json

# Default rules for deployment.
target.path = /usr/bin/
!isEmpty(target.path): INSTALLS += target

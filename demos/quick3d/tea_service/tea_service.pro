TEMPLATE = app
TARGET = tea_service
QT += qml quick 3dquick
CONFIG += qt warn_on

SOURCES += main.cpp
ICON_FILE = ../icon.png

QML_FILES = \
    qml/desktop.qml \
    qml/Teacup.qml \
    qml/TeaService.qml \
    qml/Teaspoon.qml

QML_INFRA_FILES = \
    $$QML_FILES \
    qml/teacup.bez \
    qml/teapot-body.bez \
    qml/teapot-handle.bez \
    qml/teapot-spout.bez \
    qml/teaspoon.bez

CATEGORY = demos
include(../../../pkg.pri)

OTHER_FILES += \
    mt.qml \
    $$QML_INFRA_FILES \
    tea_service.rc

INSTALL_DIRS = qml
mt: INSTALL_FILES = mt.qml

RC_FILE = tea_service.rc

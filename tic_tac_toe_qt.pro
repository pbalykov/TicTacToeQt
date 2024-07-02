QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += lrelease
CONFIG += embed_translations


SOURCES += \
    src/cell.cpp \
    src/descriptions.cpp \
    src/main.cpp \
    src/root.cpp \
    src/tic_tac_toe.cpp

HEADERS += \
    include/cell.hpp \
    include/descriptions.hpp \
    include/root.hpp \
    include/tic_tac_toe.hpp

FORMS += \
    src/ui/descriptions.ui \
    src/ui/root.ui

TRANSLATIONS += \
    translations/tic_tac_toe_qt_en_US.ts

RESOURCES += \
    resources/resources.qrc

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    cell.cpp \
    main.cpp \
    root.cpp \
    tic_tac_toe.cpp

HEADERS += \
    cell.hpp \
    root.hpp \
    tic_tac_toe.hpp

FORMS += \
    root.ui

TRANSLATIONS += \
    tic_tac_toe_qt_en_US.ts

CONFIG += lrelease
CONFIG += embed_translations


RESOURCES += \
    resources.qrc

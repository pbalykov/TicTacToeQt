QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    root.cpp \
    tic_tac_toe.cpp

HEADERS += \
    root.hpp \
    tic_tac_toe.hpp

FORMS += \
    root.ui

TRANSLATIONS += \
    tic_tac_toe_qt_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

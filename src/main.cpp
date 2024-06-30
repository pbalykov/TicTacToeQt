#include "../include/root.hpp"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[]) {

    QApplication draw(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "tic_tac_toe_qt_" + QLocale(locale).name();
        if (translator.load(":/translations/" + baseName)) {
            draw.installTranslator(&translator);
            break;
        }
    }

    Root windows;
    windows.show();
    return draw.exec();
}

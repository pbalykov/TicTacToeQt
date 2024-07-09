/****************************************************************************
 **                                                                        **
 **                           TicTacToeQt GUI игра                         **
 **                                                                        **
 **  Эта программа является свободным программным обеспечением: вы можете  **
 **  распространять ее и/или модифицировать в соответствии с условиями     **
 **  GNU General Public License, опубликованной Фондом свободного          **
 **  программного обеспечения, либо версии 3 Лицензии, либо                **
 **  (по вашему выбору) любой более поздней версии.                        **
 **                                                                        **
 **  Эта программа распространяется в надежде, что она будет полезна,      **
 **  но БЕЗ КАКИХ-ЛИБО ГАРАНТИЙ; даже без подразумеваемых гарантий         **
 **  ТОВАРНАЯ ПРИГОДНОСТЬ или ПРИГОДНОСТЬ ДЛЯ ОПРЕДЕЛЕННОЙ ЦЕЛИ. Увидеть   **
 **  GNU General Public License для получения более подробной информации.  **
 **                                                                        **
 **  Вы должны были получить копию GNU General Public License вместе с     **
 **  этой программой.  Если нет, смотрите http://www.gnu.org/licenses/.    **
 **                                                                        **
 ****************************************************************************
 **          Author: pbalykov                                              **
 ** Website/Contact: https://github.com/pbalykov                           **
 **            Date: 09.07.24                                              **  
 **         Version: 1.0.0                                                 **
 ****************************************************************************/

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

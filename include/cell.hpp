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

#ifndef CELL_HPP
#define CELL_HPP

#include <QPushButton>

enum TYPE_CELL {
    CROSS,
    ZERO,
};

class Cell : public QPushButton {
public:
    static constexpr const char* CSS_DEFAULT = "";
    static constexpr const char* CSS_ZERO = "color: #008000;";
    static constexpr const char* CSS_CROSS = "color: #D2691E;";
    static constexpr const char* SUMBOL_ZERO = "O";
    static constexpr const char* SUMBOL_CROSS = "X";
    static constexpr const char* SUMBOL_DEFAULT = "";

    Cell(QWidget* parent = nullptr);
    void setCell(TYPE_CELL value);
    void clear();

private:
    bool isActive;

};

#endif // CELL_HPP

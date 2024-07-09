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

#include "../include/cell.hpp"

Cell::Cell(QWidget* parent) : QPushButton(parent), isActive(true) {}

void Cell::setCell(TYPE_CELL value) {
    if (!this->isActive) {
        return ;
    }
    switch (value) {
        case TYPE_CELL::CROSS :
            this->setStyleSheet(CSS_CROSS);
            this->setText(SUMBOL_CROSS);
            break;
        case TYPE_CELL::ZERO :
            this->setStyleSheet(CSS_ZERO);
            this->setText(SUMBOL_ZERO);
            break;
        default :
            return ;
    }
    this->isActive = false;
    this->setEnabled(this->isActive);
    return ;
}

void Cell::clear() {
    this->isActive = true;
    this->setStyleSheet(CSS_DEFAULT);
    this->setText(SUMBOL_DEFAULT);
    this->setEnabled(this->isActive);
}

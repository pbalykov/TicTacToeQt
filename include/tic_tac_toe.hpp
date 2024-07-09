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

#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <vector>

class TicTacToe {
public:
    static constexpr short LEN = 3;
    static constexpr short PLAYER_COUNT = 2;

    enum class CELL_VALUE {
        NONE = 0,
        ZERO = 1,
        CROSS = -1,
    };

    enum class COMPLEXITY {
        LIGHT = 1,
        AVERAGE = LEN ,
        COMPLEX = LEN * LEN,
    };
    
    TicTacToe(COMPLEXITY complexity = COMPLEXITY::LIGHT,
              CELL_VALUE first_move = CELL_VALUE::CROSS);
    
    CELL_VALUE getFirstMove() const;

    bool getEndGame() const;
    CELL_VALUE getWing() const;

    CELL_VALUE setValue(short index);
    std::pair<CELL_VALUE, int> setBot();   

private:
    std::pair<int, int> _bot(int score, CELL_VALUE cell, int score_complexity) ;
    std::pair<int, int> _max(std::vector<std::pair<int, int> >& arr);
    std::pair<int, int> _min(std::vector<std::pair<int, int> >& arr);

    CELL_VALUE _getCellValue() const;

    short _data[LEN][LEN] = {{0}, {0}, {0}};
    short _score;
    bool _game;
    COMPLEXITY _complexity;
    CELL_VALUE _first_move;

};

#endif

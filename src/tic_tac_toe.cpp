#include "../include/tic_tac_toe.hpp"

#include <cmath>
#include <cstdlib>
#include <vector>

std::pair<int, int> TicTacToe::_max(std::vector<std::pair<int, int> >& arr) {
    int score = 0;
    int max = -LEN * LEN;
    for (auto i : arr) {        
        if ( i.first > max ) {
            max = i.first;
            score = 1;
        } else if ( i.first == max ) {
            score++;
        }
    }
    int rand = std::rand() % score;
    for  (auto i : arr )
        if ( i.first == max && !rand--)
            return i;
    return {0, 0};
}

std::pair<int, int> TicTacToe::_min(std::vector<std::pair<int, int> >& arr) {
    int score = 0;
    int min = LEN * LEN;
    for (auto i : arr) {
        if ( i.first < min ) {
            min = i.first;
            score = 1;
        } else if ( i.first == min ) {
            score++;
        }
    }
    int rand = std::rand() % score;
    for  (auto i : arr )
        if ( i.first == min && !rand--)
            return i;
    return {0, 0};
}

TicTacToe::CELL_VALUE TicTacToe::_getCellValue() const {
    int surplus = this->_score % PLAYER_COUNT;
    CELL_VALUE retValue;
    switch ( this->_first_move ) {
        case ( CELL_VALUE::CROSS ) :
            retValue = surplus ? CELL_VALUE::ZERO : CELL_VALUE::CROSS;
            break;
        case ( CELL_VALUE::ZERO ) :
            retValue = surplus ? CELL_VALUE::CROSS : CELL_VALUE::ZERO;
            break;
        default:
            retValue = CELL_VALUE::NONE;
            break;
    }
    return retValue;
}

std::pair<int, int> TicTacToe::_bot(int score, CELL_VALUE cell, int score_complexity) {
    if ( score == 0 ) {
        return {static_cast<int>(cell), std::rand() % (LEN * LEN)};
    }
    auto wing = getWing();
    if ( wing != CELL_VALUE::NONE )
        return {static_cast<int>(wing), 0};
    if ( score == LEN * LEN ||
         score_complexity >= static_cast<int>(this->_complexity) )
        return {0, -1};
    std::vector<std::pair<int, int> > arr;
    CELL_VALUE newCell = (cell == CELL_VALUE::CROSS ?
                              CELL_VALUE::ZERO : CELL_VALUE::CROSS);
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if ( this->_data[i][j] == 0 ) {
                this->_data[i][j] = static_cast<short>(cell);
                auto value = this->_bot(score + 1, newCell, score_complexity + 1);
                value.second = i * LEN + j;
                this->_data[i][j] = 0;
                arr.push_back(value);
            }
        }
    }
    if ( cell == CELL_VALUE::ZERO ) {
        return this->_max(arr);
    }
    return this->_min(arr);
}

TicTacToe::TicTacToe(COMPLEXITY complexity, CELL_VALUE first_move) :
    _score(0), _game(true), _complexity(complexity), _first_move(first_move) {}

TicTacToe::CELL_VALUE TicTacToe::getFirstMove() const {
    return this->_first_move;
}

TicTacToe::CELL_VALUE TicTacToe::setValue(short index) {
    if ( !this->_game ) {
        return CELL_VALUE::NONE;
    }
    short x = index % LEN;
    short y = index / LEN;
    if  ( !this->_data[y][x] ) {
        this->_data[y][x] = static_cast<int>(this->_getCellValue());
        this->_game = this->getWing() != CELL_VALUE::NONE ||
                                    ++this->_score == LEN * LEN ? false : true;
        return static_cast<CELL_VALUE>(this->_data[y][x]);
    }
    return CELL_VALUE::NONE;
}

bool TicTacToe::getEndGame() const {
    return !this->_game;
}

TicTacToe::CELL_VALUE TicTacToe::getWing() const {
    for (int i = 0; i < LEN; i++) {
        if ( this->_data[i][0] && this->_data[i][0] == this->_data[i][1] && 
             this->_data[i][1] == this->_data[i][2] ) {
            return static_cast<CELL_VALUE>(this->_data[i][0]);
        }
        if ( this->_data[0][i] && this->_data[0][i] == this->_data[1][i] && 
             this->_data[1][i] == this->_data[2][i] ) {
            return static_cast<CELL_VALUE>(this->_data[0][i]);
        }
    }
    if ( this->_data[0][0] && this->_data[0][0] == this->_data[1][1] && 
             this->_data[1][1] == this->_data[2][2] ) {
            return static_cast<CELL_VALUE>(this->_data[0][0]);
    }
    if ( this->_data[0][2] && this->_data[0][2] == this->_data[1][1] && 
             this->_data[1][1] == this->_data[2][0] ) {
            return static_cast<CELL_VALUE>(this->_data[0][2]);
    }
    return CELL_VALUE::NONE;
}       


std::pair<TicTacToe::CELL_VALUE, int> TicTacToe::setBot() {
    if ( !this->_game ) {
        return {CELL_VALUE::NONE, -1};
    }
    CELL_VALUE cell = this->_getCellValue();
    auto value = this->_bot(this->_score, cell, 0);
    if ( value.second == -1 ) {
        return {CELL_VALUE::NONE, -1};
    }
    auto value_cell = this->setValue(value.second);
    return {value_cell, value.second}; 
}

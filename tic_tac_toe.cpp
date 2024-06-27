#include "tic_tac_toe.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <QDebug>

std::pair<int, int> TicTacToe::_max(std::vector<std::pair<int, int> >& arr) {
    int score = 0;
    int max = -1;
    for (auto i : arr) {
        if ( i.first > max ) {
            max = i.first;
            score = 1;
        } else if ( i.first == max ) {
            score++;
        }
    }
    int rand = std::rand() % score;
    for  (auto i : arr ) {
        if ( i.first == max && !rand--) {
            return i;
        }
    }
    return {0, 0};
}

std::pair<int, int> TicTacToe::_min(std::vector<std::pair<int, int> >& arr) {
    int score = 0;
    int min = LEN * LEN + 1;
    for (auto i : arr) {
        if ( i.first < min ) {
            min = i.first;
            score = 1;
        } else if ( i.first == min ) {
            score++;
        }
    }
    int rand = std::rand() % score;
    for  (auto i : arr ) {
        if ( i.first == min && !rand--) {
            return i;
        }
    }
    return {0, 0};
}

std::pair<int, int> TicTacToe::_bot(int score, CELL_VALUE cell) {
    auto wing = getWing();
    if ( wing != CELL_VALUE::NONE ) {
        return {static_cast<short>(wing), 0};
    }
    if ( score == LEN * LEN + 1 )  {
        return {0, -1};
    }
    std::vector<std::pair<int, int> > arr;
    CELL_VALUE newCell = (cell == CELL_VALUE::CROSS ? 
                                        CELL_VALUE::ZERO : CELL_VALUE::CROSS);
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if ( this->_data[i][j] == 0 ) {
                this->_data[i][j] = static_cast<short>(cell);
                auto value = this->_bot(score + 1, newCell);
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

TicTacToe::TicTacToe() : _score(0), _game(true) {
    return ;
}

TicTacToe::CELL_VALUE TicTacToe::setValue(short index) {
    if ( !this->_game ) {
        return CELL_VALUE::NONE;
    }
    short x = index % LEN;
    short y = index / LEN;
    if  ( !this->_data[y][x] ) {
        this->_data[y][x] = this->_score % 2 == 0 ?
             static_cast<int>(CELL_VALUE::CROSS) : static_cast<int>(CELL_VALUE::ZERO);
        qDebug() << this->_data[y][x];
        this->_game = this->getWing() != CELL_VALUE::NONE || this->_score == LEN * LEN ? false : true;
        this->_score++;
        return static_cast<CELL_VALUE>(this->_data[y][x]);
    }
    return CELL_VALUE::NONE;
}

bool TicTacToe::getEndGame() const {
    return this->_game;
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
    CELL_VALUE cell = (this->_score + 1) % 2 ? CELL_VALUE::CROSS : CELL_VALUE::ZERO;
    auto value = this->_bot(this->_score + 1, cell);
    if ( value.second == -1 ) {
        return {CELL_VALUE::NONE, -1};
    }
    auto value_cell = this->setValue(value.second);
    return {value_cell, value.second}; 
}

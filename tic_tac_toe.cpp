#include "tic_tac_toe.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iostream>

std::pair<int, int> TicTacToe::_max(std::vector<std::pair<int, int> >& arr) {
    int score = 0;
    int max = -1;
    for (auto i : arr) {
        printf("<%d %d>  ", i.first, i.second);
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
            printf("\nMax = <%d %d>\n", i.first, i.second);
            return i;
        }
    }
    return {0, 0};
}

std::pair<int, int> TicTacToe::_min(std::vector<std::pair<int, int> >& arr) {
    int score = 0;
    int min = LEN * LEN + 1;
    printf("Min: ");
    for (auto i : arr) {
        printf("<%d %d>  ", i.first, i.second);
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
            printf("\nMin = <%d %d>\n", i.first, i.second);
            return i;
        }
    }
    return {0, 0};
}

std::pair<int, int> TicTacToe::_bot(int score, CELL_VALUE cell) {
    auto wing = getEndGame();
    if ( wing != CELL_VALUE::NONE ) {
        printf("Wing %d\n", wing);
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
    short x = index % 3;
    short y = index / LEN;
    if  ( this->_data[y][x] == 0 ) {
        this->_data[y][x] = this->_score++ % 2 == 0 ? 1 : -1;
  //      this->_game = this->getEndGame() != CELL_VALUE::NONE : ;
        return static_cast<CELL_VALUE>(this->_data[y][x]);
    }
    return CELL_VALUE::NONE;
}

TicTacToe::CELL_VALUE TicTacToe::getEndGame() const {
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
/*
    int diagonals_first = 0, diagonals_second = 0;
    for (int i = 0; i < LEN; i++) {
        int columns_x = 0, columns_y = 0;
        for (int j = 0; j < LEN; j++) {
            columns_x += this->_data[i][j];
            columns_y += this->_data[j][i];
        }
        if ( std::abs(columns_x) == LEN || std::abs(columns_y) == LEN )
            return true;
        diagonals_first += this->_data[i][i];
        diagonals_second += this->_data[i][LEN - i - 1];
    }
    if ( std::abs(diagonals_first) == LEN || 
            std::abs(diagonals_second) == LEN ) 
        return true;
    return false;   
}*/


std::pair<TicTacToe::CELL_VALUE, int> TicTacToe::setBot() {
    auto value = this->_bot(this->_score + 1, CELL_VALUE::CROSS);
    if ( value.second == -1 ) {
        return {CELL_VALUE::NONE, -1};
    }
    auto value_cell = this->setValue(value.second);
    return {value_cell, value.second}; 
}

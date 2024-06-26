#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <utility>

class TicTacToe {
public:
    enum class CELL_VALUE {
        NONE = 0,
        ZERO = 1,
        CROSS = -1,
    };
    
    static constexpr short LEN = 3;
    TicTacToe();
    CELL_VALUE setValue(short index);
    
    bool getEndGame() const;
    CELL_VALUE getWing() const;
    std::pair<CELL_VALUE, int> setBot();   

private:
    std::pair<int, int> _bot(int score, CELL_VALUE cell);
    std::pair<int, int> _max(std::vector<std::pair<int, int> >& arr);
    std::pair<int, int> _min(std::vector<std::pair<int, int> >& arr);

    short _data[LEN][LEN] = {{0}, {0}, {0}};
    short _score;
    bool _game;

};

#endif // TIC_TAC_TOE_HPP

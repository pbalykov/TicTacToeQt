#ifndef CELL_HPP
#define CELL_HPP

#include <QPushButton>

enum TYPE_CELL {
    CROSS,
    ZERO,
};

class Cell : public QPushButton {
    static constexpr const char* CSS_DEFAULT = "";
    static constexpr const char* CSS_ZERO = "QPushButton { color: #008000;}";
    static constexpr const char* CSS_CROSS = "QPushButton { color: #D2691E;}";
    static constexpr const char* SUMBOL_ZERO = "O";
    static constexpr const char* SUMBOL_CROSS = "X";
    static constexpr const char* SUMBOL_DEFAULT = "";

public:
    Cell(QWidget* parent = nullptr);
    void setCell(TYPE_CELL value);
    void clear();

private:
    bool isActive;

};

#endif // CELL_HPP

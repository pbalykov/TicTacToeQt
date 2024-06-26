#ifndef CELL_HPP
#define CELL_HPP

#include <QPushButton>

enum TYPE_CELL {
    CROSS,
    ZERO,
};

class Cell : public QPushButton {
public:
    Cell(QWidget* parent = nullptr);
    void setCell(TYPE_CELL value);
    void clear();
    void offOnActive();

private:
    bool isActive;

};

#endif // CELL_HPP

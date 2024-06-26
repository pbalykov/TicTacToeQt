#include "cell.hpp"

Cell::Cell(QWidget* parent) : QPushButton(parent), isActive(true) {}

void Cell::setCell(TYPE_CELL value) {
    if (!this->isActive) {
        return ;
    }
    switch (value) {
        case TYPE_CELL::CROSS :
            this->setStyleSheet(
                    "QPushButton { color: #D2691E;}");
            this->setText("X");
            break;
        case TYPE_CELL::ZERO :
            this->setStyleSheet(
                "QPushButton { color: #008000;}");
            this->setText("0");
            break;
        define :
            return ;
    }
    this->isActive = false;
    this->setEnabled(this->isActive);
    return ;
}

void Cell::clear() {
    this->isActive = true;
    this->setStyleSheet("");
    this->setText("");
    this->setEnabled(this->isActive);
}

void Cell::offOnActive() {
    if ( isActive ) {
        this->setEnabled(false);
    }
}

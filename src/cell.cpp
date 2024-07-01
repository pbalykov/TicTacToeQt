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

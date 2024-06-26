#include "root.hpp"
#include "ui_root.h"


Root::Root(QWidget* parent) : QMainWindow(parent)
    , _ui(new Ui::Root) {

    this->_ui->setupUi(this);
    this->_ui->updateButton->setIcon(QIcon(":/image/update.jpg"));
    this->_ui->updateButton->setIconSize(QSize(this->_ui->updateButton->size()));
    this->_button_cell = QVector<Cell*>(
                {this->_ui->cell1, this->_ui->cell2, this->_ui->cell3,
                 this->_ui->cell4, this->_ui->cell5, this->_ui->cell6,
                 this->_ui->cell7, this->_ui->cell8, this->_ui->cell9}
                );

    int caunt = 0;
    for (auto i : this->_button_cell) {
        auto f_slot = [i, caunt, this] () { this->_buttonPress(i, caunt); };
        QObject::connect(i, &Cell::clicked, f_slot);
        caunt++;
    }
    return ;
}

Root::~Root() {
    delete this->_ui;
    return ;
}

void Root::_buttonPress(Cell *value, int index) {
    auto type_cell = this->_game.setValue(index);
    switch ( type_cell ) {
        case TicTacToe::CELL_VALUE::ZERO :
            this->_button_cell[index]->setCell(TYPE_CELL::ZERO);
            break;
        case TicTacToe::CELL_VALUE::CROSS :
            this->_button_cell[index]->setCell(TYPE_CELL::CROSS);
            break;
        default :
            return ;
    }
    auto valueBot = this->_game.setBot();
    if ( valueBot.first == TicTacToe::CELL_VALUE::NONE ) {
        return ;
    }
    this->_button_cell[valueBot.second]->setCell(TYPE_CELL::ZERO);
    return ;
}



void Root::on_updateButton_clicked() {
    qDebug() << "Restart";
    for (auto i : this->_button_cell) {
        i->clear();
    }
    this->_game = TicTacToe();
    return ;
}


#include "root.hpp"
#include "ui_root.h"


Root::Root(QWidget* parent) : QMainWindow(parent)
    , _ui(new Ui::Root) {

    this->_ui->setupUi(this);
    this->_ui->updateButton->setIcon(QIcon(":/image/update.jpg"));
    this->_ui->updateButton->setIconSize(QSize(this->_ui->updateButton->size()));
    this->_button_cell = QVector<QPushButton*>(
                {this->_ui->cell1, this->_ui->cell2, this->_ui->cell3,
                 this->_ui->cell4, this->_ui->cell5, this->_ui->cell6,
                 this->_ui->cell7, this->_ui->cell8, this->_ui->cell9}
                );

    int caunt = 0;
    for (auto i : this->_button_cell) {
        auto f_slot = [i, caunt, this] () { this->_buttonPress(i, caunt); };
        QObject::connect(i, &QPushButton::clicked, f_slot);
        caunt++;
    }
    return ;
}

Root::~Root() {
    delete this->_ui;
    return ;
}

void Root::_buttonPress(QPushButton *value, int index) {
    auto type_cell = this->_game.setValue(index);
    switch ( type_cell ) {
        case TicTacToe::CELL_VALUE::ZERO :
            value->setText("X");
            value->setEnabled(false);
            break;
        case TicTacToe::CELL_VALUE::CROSS :
            value->setText("0");
            value->setEnabled(false);
            break;
        default :
            return ;
    }
    auto valueBot = this->_game.setBot();
    if ( valueBot.first == TicTacToe::CELL_VALUE::NONE ) {
        return ;
    }
    qDebug() << valueBot.second;
    this->_button_cell[valueBot.second]->setText("0");
    this->_button_cell[valueBot.second]->setEnabled(false);
    return ;
}



void Root::on_updateButton_clicked() {
    qDebug() << "Restart";
    for (auto i : this->_button_cell) {
        i->setText("");
        i->setEnabled(true);
    }
    this->_game = TicTacToe();
    return ;
}


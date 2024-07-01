#include "../include/root.hpp"
#include "../include/descriptions.hpp"

#include "ui_root.h"

#include <QActionGroup>
#ifdef QT_DEBUG
#include <QDebug>
#endif


Root::Root(QWidget* parent) : QMainWindow(parent), _ui(new Ui::Root),
    _complexity_game(TicTacToe::COMPLEXITY::AVERAGE), _game(_complexity_game)
{

    this->_ui->setupUi(this);
    this->setWindowTitle(NAME_WINDOW);
    this->_ui->updateButton->setIcon(QIcon(IMAGE_UPDATE));
    this->_ui->updateButton->setIconSize(QSize(this->_ui->updateButton->size()));
    this->_button_cell = QVector<Cell*>(
                {this->_ui->cell1, this->_ui->cell2, this->_ui->cell3,
                 this->_ui->cell4, this->_ui->cell5, this->_ui->cell6,
                 this->_ui->cell7, this->_ui->cell8, this->_ui->cell9}
                );

    int caunt = 0;
    for (auto i : this->_button_cell) {
        auto f_slot = [caunt, this] () { this->_buttonPress(caunt); };
        QObject::connect(i, &Cell::clicked, f_slot);
        caunt++;
    }
    QActionGroup *group = new QActionGroup(this);
    group->addAction(this->_ui->complexity_1);
    group->addAction(this->_ui->complexity_2);
    group->addAction(this->_ui->complexity_3);
    group->setExclusive(true);
}

Root::~Root() {
    delete this->_ui;
}

void Root::_buttonPress(int index) {
    auto type_cell = this->_game.setValue(index);
    this->_installCell(index, type_cell);
    auto valueBot = this->_game.setBot();
    this->_installCell(valueBot.second, valueBot.first);
}

void Root::_installCell(int index, TicTacToe::CELL_VALUE type_cell) {
    switch ( type_cell ) {
        case TicTacToe::CELL_VALUE::ZERO :
            this->_button_cell[index]->setCell(TYPE_CELL::ZERO);
            break;
        case TicTacToe::CELL_VALUE::CROSS :
            this->_button_cell[index]->setCell(TYPE_CELL::CROSS);
            break;
        default :
            break;
    }
    return ;
}

void Root::on_updateButton_clicked() {
    for (auto i : this->_button_cell) {
        i->clear();
    }
    this->_game = TicTacToe(this->_complexity_game);
    return ;
}

void Root::on_action_exit_triggered() {
    this->close();
    return ;
}

void Root::on_new_game_triggered() {
    this->on_updateButton_clicked();
    return ;
}

void Root::on_call_help_triggered() {
    Descriptions* secondWindow = new Descriptions(this);
    secondWindow->exec();
}

void Root::on_complexity_1_triggered() {
    this->_complexity_game = TicTacToe::COMPLEXITY::LIGHT;
    this->on_updateButton_clicked();
}

void Root::on_complexity_2_triggered() {
    this->_complexity_game = TicTacToe::COMPLEXITY::AVERAGE;
    this->on_updateButton_clicked();
}

void Root::on_complexity_3_triggered() {
    this->_complexity_game = TicTacToe::COMPLEXITY::COMPLEX;
    this->on_updateButton_clicked();
}

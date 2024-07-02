#include "../include/root.hpp"
#include "../include/descriptions.hpp"

#include "ui_root.h"

#include <QActionGroup>
#ifdef QT_DEBUG
#include <QDebug>
#endif


Root::Root(QWidget* parent) : QMainWindow(parent), _ui(new Ui::Root),
    _complexity_game(TicTacToe::COMPLEXITY::AVERAGE), _game(_complexity_game),
  _isTwoPlayers(false)
{

    this->_ui->setupUi(this);
    this->setWindowTitle(NAME_WINDOW);

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
    this->_create_group();
}

Root::~Root() {
    delete this->group1;
    delete this->group2;
    delete this->_ui;
}

void Root::_create_group() {
    this->group1 = new QActionGroup(this);
    this->group1->addAction(this->_ui->complexity_1);
    this->group1->addAction(this->_ui->complexity_2);
    this->group1->addAction(this->_ui->complexity_3);
    this->group1->setExclusive(true);

    this->group2 = new QActionGroup(this);
    this->group2->addAction(this->_ui->first_player);
    this->group2->addAction(this->_ui->second_player);
    this->group2->setExclusive(true);
}

void Root::_buttonPress(int index) {
    if ( this->_game.getEndGame() ) {
        return ;
    }
    auto type_cell = this->_game.setValue(index);
    this->_installCell(index, type_cell);
    if ( !this->_isTwoPlayers ) {
        auto valueBot = this->_game.setBot();
        this->_installCell(valueBot.second, valueBot.first);
    }
    if ( this->_game.getEndGame() ) {
        int value = 0;
#ifdef QT_DEBUG
        qDebug() << "END_GAME";
#endif
        switch ( this->_game.getWing() ) {
            case TicTacToe::CELL_VALUE::ZERO :
                value = this->_ui->lcdZero->value() + 1;
                this->_ui->lcdZero->display(value);
                break;
            case TicTacToe::CELL_VALUE::CROSS :
                value = this->_ui->lcdCross->value() + 1;
                this->_ui->lcdCross->display(value);
                break;
            default:
                break;
        }
    }
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
}

void Root::on_action_exit_triggered() {
    this->close();
}

void Root::on_new_game_triggered() {
    this->on_updateButton_clicked();
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

void Root::on_first_player_triggered() {
    if ( !this->_isTwoPlayers ) {
        return ;
    }
    this->_isTwoPlayers = false;
    this->_ui->menu_complexity->setEnabled(true);
    this->on_updateButton_clicked();
}

void Root::on_second_player_triggered() {
    if ( this->_isTwoPlayers ) {
        return ;
    }
    this->_isTwoPlayers = true;
    this->_ui->menu_complexity->setEnabled(false);
    this->on_updateButton_clicked();
}

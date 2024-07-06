#ifndef ROOT_H
#define ROOT_H

#include <QActionGroup>
#include <QMainWindow>
#include <QPushButton>
#include <QVector>

#include "tic_tac_toe.hpp"
#include "cell.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Root; }
QT_END_NAMESPACE

class Root : public QMainWindow {
    Q_OBJECT
    
    static constexpr const char* NAME_WINDOW = "TicTacToeQt";
    static constexpr const char* IMAGE_UPDATE = ":/image/update.png";

public:
    Root(QWidget* parent = nullptr);
    ~Root();

private slots:
    void on_updateButton_clicked();

    void on_action_exit_triggered();
    void on_new_game_triggered();
    void on_call_help_triggered();

    void on_complexity_1_triggered();
    void on_complexity_2_triggered();
    void on_complexity_3_triggered();

    void on_first_player_triggered();
    void on_second_player_triggered();

private:
    void _create_group();

    void _endGame();
    void _installCell(int index, TicTacToe::CELL_VALUE type_cell);
    void _buttonPress(int index);

    Ui::Root* _ui;

    QVector<Cell*> _button_cell;

    TicTacToe::COMPLEXITY _complexity_game;
    TicTacToe::CELL_VALUE _first_move;
    TicTacToe _game;
    bool _isTwoPlayers;


    QActionGroup *group1;
    QActionGroup *group2;
};

#endif

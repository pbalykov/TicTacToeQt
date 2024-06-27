#ifndef ROOT_H
#define ROOT_H

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

public:
    Root(QWidget* parent = nullptr);
    ~Root();

private slots:
    void on_updateButton_clicked();

private:
    void _installCell(int index, TicTacToe::CELL_VALUE type_cell);
    void _buttonPress(int index);

    Ui::Root* _ui;
    QVector<Cell*> _button_cell;
    TicTacToe _game;
};

#endif

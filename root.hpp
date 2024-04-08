#ifndef ROOT_H
#define ROOT_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include "tic_tac_toe.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Root; }
QT_END_NAMESPACE

class Root : public QMainWindow {
    Q_OBJECT

public:
    Root(QWidget* parent = nullptr);
    ~Root();

private slots:
    void on_updateButton_clicked();

private:
    void _buttonPress(QPushButton* value, int index);

    Ui::Root* _ui;
    QVector<QPushButton*> _button_cell;
    TicTacToe _game;
};

#endif

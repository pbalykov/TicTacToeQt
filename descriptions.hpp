#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP

#include <QDialog>

namespace Ui {
class Descriptions;
}

class Descriptions : public QDialog {
    Q_OBJECT
    static constexpr const char* NAME_WINDOW = "О программе\"TicTacToeQt\"";
    static constexpr const char* NAME_ICON = ":/image/icon.png";

public:
    explicit Descriptions(QWidget* parent = nullptr);
    ~Descriptions();

private slots:
    void on_buttonOk_clicked();

private:
    Ui::Descriptions* _ui;
};

#endif // DESCRIPTIONS_HPP

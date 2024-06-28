#include "descriptions.hpp"
#include "ui_descriptions.h"

Descriptions::Descriptions(QWidget* parent) :
    QDialog(parent), _ui(new Ui::Descriptions)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->_ui->setupUi(this);
    this->setWindowTitle(NAME_WINDOW);

}

Descriptions::~Descriptions() {
    delete this->_ui;
}

void Descriptions::on_buttonOk_clicked() {
    this->close();
}

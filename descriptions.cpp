#include "descriptions.hpp"
#include "ui_descriptions.h"

Descriptions::Descriptions(QWidget* parent) :
    QDialog(parent), _ui(new Ui::Descriptions)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->_ui->setupUi(this);
    this->setWindowTitle(NAME_WINDOW);

    int maxWidth = this->_ui->icon->width();
    int maxHeight = this->_ui->icon->height();
    QPixmap icon(NAME_ICON);
    this->_ui->icon->setPixmap(icon.scaled(maxWidth, maxHeight, Qt::IgnoreAspectRatio));
    this->_ui->icon->setScaledContents(true);
}

Descriptions::~Descriptions() {
    delete this->_ui;
}

void Descriptions::on_buttonOk_clicked() {
    this->close();
}

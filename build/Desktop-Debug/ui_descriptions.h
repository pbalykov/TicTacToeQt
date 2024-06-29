/********************************************************************************
** Form generated from reading UI file 'descriptions.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCRIPTIONS_H
#define UI_DESCRIPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Descriptions
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonOk;

    void setupUi(QDialog *Descriptions)
    {
        if (Descriptions->objectName().isEmpty())
            Descriptions->setObjectName("Descriptions");
        Descriptions->resize(370, 172);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Descriptions->sizePolicy().hasHeightForWidth());
        Descriptions->setSizePolicy(sizePolicy);
        Descriptions->setMinimumSize(QSize(370, 172));
        Descriptions->setMaximumSize(QSize(370, 172));
        horizontalLayout_2 = new QHBoxLayout(Descriptions);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        icon = new QLabel(Descriptions);
        icon->setObjectName("icon");
        icon->setMaximumSize(QSize(80, 80));

        horizontalLayout_2->addWidget(icon);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(Descriptions);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonOk = new QPushButton(Descriptions);
        buttonOk->setObjectName("buttonOk");

        horizontalLayout->addWidget(buttonOk);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Descriptions);

        QMetaObject::connectSlotsByName(Descriptions);
    } // setupUi

    void retranslateUi(QDialog *Descriptions)
    {
        Descriptions->setWindowTitle(QCoreApplication::translate("Descriptions", "Dialog", nullptr));
        icon->setText(QCoreApplication::translate("Descriptions", "image", nullptr));
        label_2->setText(QCoreApplication::translate("Descriptions", "<html><head/><body><p><span style=\" font-weight:700;\">TicTacToeQt v. beta</span><br/>\320\220\320\262\321\202\320\276\321\200: pbalykov<br/>\320\233\320\270\321\206\320\265\320\275\320\267\320\270\321\217: <a href=\"https://github.com/pbalykov/tic_tac_toe_qt/blob/main/LICENSE\"><span style=\" text-decoration: underline; color:#007af4;\">GPL-3.0 license</span></a><br/>\320\230\321\201\321\205\320\276\320\264\320\275\320\270\320\272\320\270: <a href=\"https://github.com/pbalykov/tic_tac_toe_qt\"><span style=\" text-decoration: underline; color:#007af4;\">github.com</span></a><br/>Githab \320\260\320\262\321\202\320\276\321\200\320\260: <a href=\"https://github.com/pbalykov\"><span style=\" text-decoration: underline; color:#007af4;\">https://github.com/pbalykov</span></a></p></body></html>", nullptr));
        buttonOk->setText(QCoreApplication::translate("Descriptions", "\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Descriptions: public Ui_Descriptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCRIPTIONS_H

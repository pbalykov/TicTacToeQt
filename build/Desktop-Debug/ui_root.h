/********************************************************************************
** Form generated from reading UI file 'root.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOT_H
#define UI_ROOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cell.hpp"

QT_BEGIN_NAMESPACE

class Ui_Root
{
public:
    QAction *abautProgram;
    QAction *new_game;
    QAction *action_exit;
    QAction *call_help;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *updateButton;
    QSpacerItem *horizontalSpacer_4;
    QLCDNumber *lcdNumber_2;
    QGridLayout *folder;
    Cell *cell2;
    Cell *cell8;
    Cell *cell5;
    Cell *cell1;
    QSpacerItem *horizontalSpacer_2;
    Cell *cell9;
    Cell *cell4;
    Cell *cell3;
    Cell *cell6;
    Cell *cell7;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *Root)
    {
        if (Root->objectName().isEmpty())
            Root->setObjectName("Root");
        Root->resize(277, 354);
        Root->setMinimumSize(QSize(277, 354));
        Root->setMaximumSize(QSize(277, 354));
        abautProgram = new QAction(Root);
        abautProgram->setObjectName("abautProgram");
        new_game = new QAction(Root);
        new_game->setObjectName("new_game");
        action_exit = new QAction(Root);
        action_exit->setObjectName("action_exit");
        call_help = new QAction(Root);
        call_help->setObjectName("call_help");
        centralwidget = new QWidget(Root);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setMaximumSize(QSize(64, 60));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setMode(QLCDNumber::Dec);

        horizontalLayout->addWidget(lcdNumber);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");
        updateButton->setMaximumSize(QSize(64, 60));

        horizontalLayout->addWidget(updateButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setMaximumSize(QSize(64, 60));

        horizontalLayout->addWidget(lcdNumber_2);


        verticalLayout->addLayout(horizontalLayout);

        folder = new QGridLayout();
        folder->setSpacing(2);
        folder->setObjectName("folder");
        folder->setContentsMargins(-1, 0, -1, -1);
        cell2 = new Cell(centralwidget);
        cell2->setObjectName("cell2");
        cell2->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell2, 0, 2, 1, 1);

        cell8 = new Cell(centralwidget);
        cell8->setObjectName("cell8");
        cell8->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell8, 2, 2, 1, 1);

        cell5 = new Cell(centralwidget);
        cell5->setObjectName("cell5");
        cell5->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell5, 1, 2, 1, 1);

        cell1 = new Cell(centralwidget);
        cell1->setObjectName("cell1");
        cell1->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell1, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        folder->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        cell9 = new Cell(centralwidget);
        cell9->setObjectName("cell9");
        cell9->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell9, 2, 3, 1, 1);

        cell4 = new Cell(centralwidget);
        cell4->setObjectName("cell4");
        cell4->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell4, 1, 1, 1, 1);

        cell3 = new Cell(centralwidget);
        cell3->setObjectName("cell3");
        cell3->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell3, 0, 3, 1, 1);

        cell6 = new Cell(centralwidget);
        cell6->setObjectName("cell6");
        cell6->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell6, 1, 3, 1, 1);

        cell7 = new Cell(centralwidget);
        cell7->setObjectName("cell7");
        cell7->setMinimumSize(QSize(65, 80));

        folder->addWidget(cell7, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        folder->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        verticalLayout->addLayout(folder);

        Root->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Root);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 277, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        Root->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(new_game);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu_2->addAction(call_help);

        retranslateUi(Root);

        QMetaObject::connectSlotsByName(Root);
    } // setupUi

    void retranslateUi(QMainWindow *Root)
    {
        Root->setWindowTitle(QCoreApplication::translate("Root", "Root", nullptr));
        abautProgram->setText(QCoreApplication::translate("Root", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265...", nullptr));
        new_game->setText(QCoreApplication::translate("Root", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
#if QT_CONFIG(shortcut)
        new_game->setShortcut(QCoreApplication::translate("Root", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        action_exit->setText(QCoreApplication::translate("Root", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("Root", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        call_help->setText(QCoreApplication::translate("Root", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#if QT_CONFIG(shortcut)
        call_help->setShortcut(QCoreApplication::translate("Root", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        updateButton->setText(QString());
        cell2->setText(QString());
        cell8->setText(QString());
        cell5->setText(QString());
        cell1->setText(QString());
        cell9->setText(QString());
        cell4->setText(QString());
        cell3->setText(QString());
        cell6->setText(QString());
        cell7->setText(QString());
        menu->setTitle(QCoreApplication::translate("Root", "\320\230\320\263\321\200\320\260", nullptr));
        menu_2->setTitle(QCoreApplication::translate("Root", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Root: public Ui_Root {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOT_H

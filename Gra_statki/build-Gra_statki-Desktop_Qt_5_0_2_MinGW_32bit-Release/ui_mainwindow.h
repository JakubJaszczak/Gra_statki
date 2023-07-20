/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pbStart;
    QCheckBox *cbHorizontal;
    QCheckBox *cbVertical;
    QLabel *label;
    QSpinBox *sbShipSize;
    QLabel *label_2;
    QLabel *lb_gameState;
    QLabel *label_3;
    QPushButton *pb_Restart;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 782);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pbStart = new QPushButton(centralWidget);
        pbStart->setObjectName(QStringLiteral("pbStart"));
        pbStart->setGeometry(QRect(1180, 320, 131, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbStart->sizePolicy().hasHeightForWidth());
        pbStart->setSizePolicy(sizePolicy);
        cbHorizontal = new QCheckBox(centralWidget);
        cbHorizontal->setObjectName(QStringLiteral("cbHorizontal"));
        cbHorizontal->setEnabled(true);
        cbHorizontal->setGeometry(QRect(1180, 150, 131, 31));
        sizePolicy.setHeightForWidth(cbHorizontal->sizePolicy().hasHeightForWidth());
        cbHorizontal->setSizePolicy(sizePolicy);
        cbHorizontal->setMouseTracking(false);
        cbHorizontal->setChecked(true);
        cbHorizontal->setAutoExclusive(true);
        cbHorizontal->setTristate(false);
        cbVertical = new QCheckBox(centralWidget);
        cbVertical->setObjectName(QStringLiteral("cbVertical"));
        cbVertical->setGeometry(QRect(1180, 190, 121, 31));
        sizePolicy.setHeightForWidth(cbVertical->sizePolicy().hasHeightForWidth());
        cbVertical->setSizePolicy(sizePolicy);
        cbVertical->setAutoExclusive(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1180, 120, 121, 20));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        sbShipSize = new QSpinBox(centralWidget);
        sbShipSize->setObjectName(QStringLiteral("sbShipSize"));
        sbShipSize->setGeometry(QRect(1180, 260, 41, 31));
        sizePolicy.setHeightForWidth(sbShipSize->sizePolicy().hasHeightForWidth());
        sbShipSize->setSizePolicy(sizePolicy);
        sbShipSize->setMinimum(1);
        sbShipSize->setMaximum(4);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1180, 230, 101, 16));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        lb_gameState = new QLabel(centralWidget);
        lb_gameState->setObjectName(QStringLiteral("lb_gameState"));
        lb_gameState->setGeometry(QRect(1180, 450, 131, 21));
        sizePolicy.setHeightForWidth(lb_gameState->sizePolicy().hasHeightForWidth());
        lb_gameState->setSizePolicy(sizePolicy);
        lb_gameState->setFrameShape(QFrame::Box);
        lb_gameState->setFrameShadow(QFrame::Plain);
        lb_gameState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1180, 420, 101, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        pb_Restart = new QPushButton(centralWidget);
        pb_Restart->setObjectName(QStringLiteral("pb_Restart"));
        pb_Restart->setGeometry(QRect(1180, 490, 131, 71));
        sizePolicy.setHeightForWidth(pb_Restart->sizePolicy().hasHeightForWidth());
        pb_Restart->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1350, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pbStart->setText(QApplication::translate("MainWindow", "Start", 0));
        cbHorizontal->setText(QApplication::translate("MainWindow", "Poziomo", 0));
        cbVertical->setText(QApplication::translate("MainWindow", "Pionowo", 0));
        label->setText(QApplication::translate("MainWindow", "Rozstawienie statk\303\263w:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rozmiar statku", 0));
        lb_gameState->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Stan gry:", 0));
        pb_Restart->setText(QApplication::translate("MainWindow", "Restart", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

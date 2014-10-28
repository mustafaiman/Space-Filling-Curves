/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "curvewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionNew;
    QWidget *centralWidget;
    CurveWidget *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioLine;
    QPushButton *buttonApply;
    QRadioButton *radioBg;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSlider *sliderR;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QSlider *sliderG;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QSlider *sliderB;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *spinIterations;
    QSlider *horizontalSlider;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *checkFill;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new CurveWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 841, 768));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(850, 0, 171, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioLine = new QRadioButton(gridLayoutWidget);
        radioLine->setObjectName(QStringLiteral("radioLine"));

        gridLayout->addWidget(radioLine, 6, 0, 1, 1);

        buttonApply = new QPushButton(gridLayoutWidget);
        buttonApply->setObjectName(QStringLiteral("buttonApply"));

        gridLayout->addWidget(buttonApply, 2, 0, 1, 1);

        radioBg = new QRadioButton(gridLayoutWidget);
        radioBg->setObjectName(QStringLiteral("radioBg"));

        gridLayout->addWidget(radioBg, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        sliderR = new QSlider(gridLayoutWidget);
        sliderR->setObjectName(QStringLiteral("sliderR"));
        sliderR->setMaximum(255);
        sliderR->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(sliderR);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sliderG = new QSlider(gridLayoutWidget);
        sliderG->setObjectName(QStringLiteral("sliderG"));
        sliderG->setMaximum(255);
        sliderG->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(sliderG);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sliderB = new QSlider(gridLayoutWidget);
        sliderB->setObjectName(QStringLiteral("sliderB"));
        sliderB->setMaximum(255);
        sliderB->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(sliderB);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinIterations = new QSpinBox(gridLayoutWidget);
        spinIterations->setObjectName(QStringLiteral("spinIterations"));

        horizontalLayout_2->addWidget(spinIterations);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 11, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 0, 1, 1);

        checkFill = new QCheckBox(gridLayoutWidget);
        checkFill->setObjectName(QStringLiteral("checkFill"));

        gridLayout->addWidget(checkFill, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 10, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(setLineWidth(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        radioLine->setText(QApplication::translate("MainWindow", "Line Color", 0));
        buttonApply->setText(QApplication::translate("MainWindow", "Apply Space Filling", 0));
        radioBg->setText(QApplication::translate("MainWindow", "BackgroundColor", 0));
        label->setText(QApplication::translate("MainWindow", "Red", 0));
        label_2->setText(QApplication::translate("MainWindow", "Green", 0));
        label_3->setText(QApplication::translate("MainWindow", "Blue", 0));
        label_4->setText(QApplication::translate("MainWindow", "Iterations", 0));
        checkFill->setText(QApplication::translate("MainWindow", "Fill the polygon", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Select apopriate button to change</p><p>color and then use the sliders</p></body></html>", 0));
        label_6->setText(QApplication::translate("MainWindow", "Line Thickness", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

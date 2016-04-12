/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *logo;
    QPushButton *buttonEnter;
    QLabel *background;
    QWidget *page_2;
    QLabel *backgrounnd;
    QLabel *logoo;
    QPushButton *up;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QPushButton *pause;
    QPushButton *exitButton;
    QPushButton *dtg;
    QPushButton *dtd;
    QSlider *sliderSpeed;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(688, 636);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-111, -61, 821, 711));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        logo = new QLabel(page);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(220, 90, 371, 161));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/LOGOBLACK.png")));
        logo->setScaledContents(true);
        buttonEnter = new QPushButton(page);
        buttonEnter->setObjectName(QStringLiteral("buttonEnter"));
        buttonEnter->setGeometry(QRect(320, 450, 161, 71));
        buttonEnter->setStyleSheet(QLatin1String("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        background = new QLabel(page);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(90, 60, 651, 621));
        background->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/triangle.png")));
        background->setScaledContents(true);
        stackedWidget->addWidget(page);
        background->raise();
        logo->raise();
        buttonEnter->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        backgrounnd = new QLabel(page_2);
        backgrounnd->setObjectName(QStringLiteral("backgrounnd"));
        backgrounnd->setGeometry(QRect(90, 50, 741, 661));
        backgrounnd->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/triangle2.png")));
        backgrounnd->setScaledContents(true);
        logoo = new QLabel(page_2);
        logoo->setObjectName(QStringLiteral("logoo"));
        logoo->setGeometry(QRect(280, 90, 321, 121));
        logoo->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/LOGOBLACK.png")));
        logoo->setScaledContents(true);
        up = new QPushButton(page_2);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(250, 340, 82, 82));
        up->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        left = new QPushButton(page_2);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(130, 450, 82, 82));
        left->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        right = new QPushButton(page_2);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(370, 450, 82, 82));
        right->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        down = new QPushButton(page_2);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(250, 590, 82, 82));
        down->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        pause = new QPushButton(page_2);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(250, 460, 82, 82));
        pause->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        exitButton = new QPushButton(page_2);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(680, 80, 93, 61));
        exitButton->setStyleSheet(QLatin1String("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        dtg = new QPushButton(page_2);
        dtg->setObjectName(QStringLiteral("dtg"));
        dtg->setGeometry(QRect(540, 360, 82, 82));
        dtg->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        dtd = new QPushButton(page_2);
        dtd->setObjectName(QStringLiteral("dtd"));
        dtd->setGeometry(QRect(670, 360, 82, 82));
        dtd->setStyleSheet(QLatin1String("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        sliderSpeed = new QSlider(page_2);
        sliderSpeed->setObjectName(QStringLiteral("sliderSpeed"));
        sliderSpeed->setGeometry(QRect(560, 520, 181, 41));
        sliderSpeed->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"        border: 1px solid #999999;\n"
"        height: 2px;\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 white);\n"
"       margin: 2px 0;\n"
"    }\n"
" \n"
"    QSlider::handle:horizontal {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b0b0b0, stop:1 white);\n"
"        border: 1px solid #5c5c5c;\n"
"        width: 40px;\n"
"        margin: -6px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"        border-radius: 5px;\n"
"   }"));
        sliderSpeed->setMinimum(25);
        sliderSpeed->setMaximum(60);
        sliderSpeed->setSliderPosition(30);
        sliderSpeed->setOrientation(Qt::Horizontal);
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 480, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("8514oem"));
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 590, 161, 61));
        pushButton->setStyleSheet(QLatin1String("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 590, 171, 61));
        pushButton_2->setStyleSheet(QLatin1String("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        stackedWidget->addWidget(page_2);
        backgrounnd->raise();
        logoo->raise();
        exitButton->raise();
        up->raise();
        right->raise();
        pause->raise();
        down->raise();
        left->raise();
        dtg->raise();
        dtd->raise();
        sliderSpeed->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        logo->setText(QString());
        buttonEnter->setText(QApplication::translate("MainWindow", "ENTER", 0));
        background->setText(QString());
        backgrounnd->setText(QString());
        logoo->setText(QString());
        up->setText(QString());
        left->setText(QString());
        right->setText(QString());
        down->setText(QString());
        pause->setText(QString());
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
        dtg->setText(QString());
        dtd->setText(QString());
        label->setText(QApplication::translate("MainWindow", "SPEED", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Go to position", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Go to first position", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

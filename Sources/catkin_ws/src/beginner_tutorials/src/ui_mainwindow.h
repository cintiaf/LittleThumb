/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(688, 636);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-111, -61, 821, 711));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        logo = new QLabel(page);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(220, 90, 371, 161));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/LOGOBLACK.png")));
        logo->setScaledContents(true);
        buttonEnter = new QPushButton(page);
        buttonEnter->setObjectName(QString::fromUtf8("buttonEnter"));
        buttonEnter->setGeometry(QRect(320, 450, 161, 71));
        buttonEnter->setStyleSheet(QString::fromUtf8("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        background = new QLabel(page);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(90, 60, 651, 621));
        background->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/triangle.png")));
        background->setScaledContents(true);
        stackedWidget->addWidget(page);
        background->raise();
        logo->raise();
        buttonEnter->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        backgrounnd = new QLabel(page_2);
        backgrounnd->setObjectName(QString::fromUtf8("backgrounnd"));
        backgrounnd->setGeometry(QRect(90, 50, 741, 661));
        backgrounnd->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/triangle2.png")));
        backgrounnd->setScaledContents(true);
        logoo = new QLabel(page_2);
        logoo->setObjectName(QString::fromUtf8("logoo"));
        logoo->setGeometry(QRect(280, 90, 321, 121));
        logoo->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/New folder/LOGOBLACK.png")));
        logoo->setScaledContents(true);
        up = new QPushButton(page_2);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(250, 340, 82, 82));
        up->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        left = new QPushButton(page_2);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(130, 450, 82, 82));
        left->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        right = new QPushButton(page_2);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(370, 450, 82, 82));
        right->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        down = new QPushButton(page_2);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(250, 590, 82, 82));
        down->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        pause = new QPushButton(page_2);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(250, 460, 82, 82));
        pause->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        exitButton = new QPushButton(page_2);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(680, 80, 93, 61));
        exitButton->setStyleSheet(QString::fromUtf8("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        dtg = new QPushButton(page_2);
        dtg->setObjectName(QString::fromUtf8("dtg"));
        dtg->setGeometry(QRect(540, 360, 82, 82));
        dtg->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        dtd = new QPushButton(page_2);
        dtd->setObjectName(QString::fromUtf8("dtd"));
        dtd->setGeometry(QRect(670, 360, 82, 82));
        dtd->setStyleSheet(QString::fromUtf8("\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:40px;\n"
" border-color: #298A08;\n"
" max-width:80px;\n"
" max-height:80px;\n"
" min-width:80px;\n"
" min-height:80px;"));
        sliderSpeed = new QSlider(page_2);
        sliderSpeed->setObjectName(QString::fromUtf8("sliderSpeed"));
        sliderSpeed->setGeometry(QRect(560, 520, 181, 41));
        sliderSpeed->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
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
        sliderSpeed->setMinimum(15);
        sliderSpeed->setMaximum(60);
        sliderSpeed->setSliderPosition(30);
        sliderSpeed->setOrientation(Qt::Horizontal);
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 480, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 590, 161, 61));
        pushButton->setStyleSheet(QString::fromUtf8("		margin-top: 15px;\n"
"		margin-bottom: 15px;\n"
"		background: grey;\n"
"		border: 1px solid black;\n"
"		border-radius: 5px;\n"
"		font-size : 15px;\n"
"	color: white;\n"
"	font-family: Arial Black;\n"
"	font-size : bold;"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 590, 171, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("		margin-top: 15px;\n"
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        buttonEnter->setText(QApplication::translate("MainWindow", "ENTER", 0, QApplication::UnicodeUTF8));
        background->setText(QString());
        backgrounnd->setText(QString());
        logoo->setText(QString());
        up->setText(QString());
        left->setText(QString());
        right->setText(QString());
        down->setText(QString());
        pause->setText(QString());
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        dtg->setText(QString());
        dtd->setText(QString());
        label->setText(QApplication::translate("MainWindow", "SPEED", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Go to position", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Go to first position", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <winsock2.h>
//#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
//#include <io.h>
//#include <ws2tcpip.h>
#include <QMainWindow>
//#pragma comment(lib, "Ws2_32.lib")

#include "ros/ros.h"
#include "beginner_tutorials/graphicClient.h"

//#define _WINSOCK_DEPRECATED_NO_WARNINGS

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int argc, char **argv, QWidget *parent = 0);
    ~MainWindow();
    void getDirPath();
    void up_cmd();
    void left_cmd();
    void dmt_cmd();
    void right_cmd();
   // void update();

private slots:
    void on_buttonEnter_clicked();

    void on_exitButton_clicked();

    void on_pause_clicked();

    void on_up_pressed();

   void update();

    void on_left_pressed();

    void on_right_pressed();

    void on_down_pressed();

    void on_dtg_pressed();

    void on_dtd_pressed();

   // void on_sliderSpeed_rangeChanged(int min, int max);

   // void on_sliderSpeed_sliderReleased();

    void on_sliderSpeed_valueChanged(int value);

   // void on_path_clicked();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
   // SOCKET fd;
    std::string curPath;
    QTimer * timer;
    char params[5];
    char power;
    ros::ServiceClient _client;
    beginner_tutorials::graphicClient _srv;
};

#endif // MAINWINDOW_H

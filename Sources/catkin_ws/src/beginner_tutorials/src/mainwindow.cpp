#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QWidget>
#include <unistd.h>
#include <QTimer>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>

//#include "../Client/HandleConnection.h"
//# include <direct.h>
//# include "../Client/Connection_Win.h"

void MainWindow::getDirPath()
{
    char buf[4096];

    memset (buf, 0, 4096);
        getcwd(buf, 4096);
    std::string fullPath(buf);
            std::cout << fullPath << std::endl;
    unsigned int pos = fullPath.rfind("robotController");
    curPath = fullPath.substr(0, pos + sizeof("robotController"));
    std::cout << curPath << std::endl;
}

MainWindow::MainWindow(int argc, char **argv, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    getDirPath();
    ui->setupUi(this);
    setFixedSize(600, 600);
    power = 30;
    std::string topButton = curPath;
    topButton += "Images/top.png";
    QIcon icon(topButton.c_str());
    this->ui->up->setIconSize(QSize(88,88));
    this->ui->up->setIcon(icon);
    timer = NULL;

    std::string leftButton =  curPath;
    leftButton += "Images/left.png";
    QIcon icon2(leftButton.c_str());
    this->ui->left->setIconSize(QSize(88,88));
    this->ui->left->setIcon(icon2);

    std::string rightButton =  curPath;
    rightButton += "Images/right.png";
    QIcon icon3(rightButton.c_str());
    this->ui->right->setIconSize(QSize(88,88));
    this->ui->right->setIcon(icon3);

    std::string downButton =  curPath;
    downButton += "Images/down.png";
    QIcon icon4(downButton.c_str());
    this->ui->down->setIconSize(QSize(88,88));
    this->ui->down->setIcon(icon4);

    std::string stopButton =  curPath;
    stopButton += "Images/circle.png";
    QIcon icon6(stopButton.c_str());
    this->ui->pause->setIconSize(QSize(88,88));
    this->ui->pause->setIcon(icon6);

    std::string pathBackGround =  curPath;
    pathBackGround += "Images/triangle.png";

    QPixmap pixmap9(pathBackGround.c_str());
    this->ui->background->setPixmap(pixmap9);

    std::string pathBackGround2 =  curPath;
    pathBackGround2 += "Images/triangle2.png";
    std::cout << curPath << std::endl;
    QPixmap pixmap12(pathBackGround2.c_str());
    this->ui->backgrounnd->setPixmap(pixmap12);

    std::string dtgButton = curPath;
    dtgButton += "Images/left12.png";
    QIcon icondtg(dtgButton.c_str());
    this->ui->dtg->setIconSize(QSize(82,82));
    this->ui->dtg->setIcon(icondtg);

    std::string dtdButton = curPath;
    dtdButton += "Images/signal4.png";
    QIcon icondtd(dtdButton.c_str());
    this->ui->dtd->setIconSize(QSize(82,82));
    this->ui->dtd->setIcon(icondtd);

    std::string pathLog =  curPath;
    pathLog += "Images/LOGOBLACK.png";

    QPixmap pixmap8(pathLog.c_str());
    this->ui->logo->setPixmap(pixmap8);

    QPixmap pixmap11(pathLog.c_str());
    this->ui->logoo->setPixmap(pixmap8);

    /*
    WSADATA wsaData;
    fd = INVALID_SOCKET;
    struct addrinfo *result = NULL, hints;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed with error:" << iResult << std::endl;
    }
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    iResult = getaddrinfo("10.20.86.154", "4243", &hints, &result);
    if (iResult != 0)
    {
        std::cerr << "getaddrinfo failed with error: " << iResult << std::endl;
        WSACleanup();
    }
    fd = socket(result->ai_family, result->ai_socktype,
        result->ai_protocol);
    if (fd == INVALID_SOCKET) {
        std::cerr << "socket failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
    }
    std::cout << "1" << std::endl;
    iResult = ::connect(fd, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(fd);
        fd = INVALID_SOCKET;
    }
    freeaddrinfo(result);
    std::cout << "2" << std::endl;
    if (fd == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
    }*/

    ros::init(argc, argv, "graphic_ros_client");

    ros::NodeHandle* n = new ros::NodeHandle();
    _client = n->serviceClient<beginner_tutorials::graphicClient>("graphicClient");

    connect(ui->up, SIGNAL(released()), this, SLOT(on_pause_clicked()));
    connect(ui->down, SIGNAL(released()), this, SLOT(on_pause_clicked()));
    connect(ui->right, SIGNAL(released()), this, SLOT(on_pause_clicked()));
    connect(ui->left, SIGNAL(released()), this, SLOT(on_pause_clicked()));
    connect(ui->dtd, SIGNAL(released()), this, SLOT(on_pause_clicked()));
    connect(ui->dtg, SIGNAL(released()), this, SLOT(on_pause_clicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_buttonEnter_clicked()
{
     this->ui->stackedWidget->setCurrentIndex(1);
       setFixedSize(700, 640);
       delete ui;

}

void MainWindow::on_exitButton_clicked()
{
    std::cout << "close" << std::endl;
    //closesocket(fd);
    exit(0);
}

void MainWindow::up_cmd()
{
    /*unsigned char buf[128];

    memset(buf, 0, 128);
    buf[0] = 'G';
    buf[1] = 50;
    buf[2] = -50;
    buf[3] = 50;
    buf[4] = -50;
    buf[5] = 250;
    buf[6] = 'g';
    buf[7] = '\n';
    std::cout << buf[4] << "salut" << std::endl;
    std::cout << "dqsdq" << std::endl;
    send(fd, (char*)buf, 128, 0);*/


    _srv.request.action = 'G';
    _srv.request.engineFL = 30;
    _srv.request.engineFR = 30;
    _srv.request.engineBL = 30;
    _srv.request.engineBR = 30;
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = 30;
    params[2] = 30;
    params[3] = 30;
    params[4] = 30;
    params[5] = 'g';
  update();
}

void MainWindow::on_pause_clicked()
{
    char buf[128];
       if (timer)
       {
           timer->stop();
           timer = NULL;
       }
    usleep(10000);
    memset(buf, 0, 128);
    buf[0] = 's';
    buf[1] = ' ';
  buf[2] = ' ';
   buf[3] = ' ';
    buf[4] = ' ';
     buf[5] = ' ';
    buf[6] = 's';
    buf[7] = '\n';

    _srv.request.action = 's';
    _srv.request.engineFL = 0;
    _srv.request.engineFR = 0;
    _srv.request.engineBL = 0;
    _srv.request.engineBR = 0;
    _srv.request.time = 0;

    std::cout << "debug1" << std::endl;
    if (_client.call(_srv))
    {
        std::cout << "HERE" << std::endl;
        ROS_INFO("Sum: %ld", (long int)_srv.response.ret);
    }
    else
    {
        std::cout << "FAIL" << std::endl;
        ROS_ERROR("Failed to call service add_two_ints");
    }
    //send(fd, buf, 128, 0);std::cout << "debug2" << std::endl;
}

void MainWindow::left_cmd()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = (power /2);
    _srv.request.engineFR = power;
    _srv.request.engineBL = (power /2);
    _srv.request.engineBR = power;
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = (power /2);
    params[2] = power;
    params[3] = (power /2);
    params[4] = power;
    params[5] = 'l';
     update();
}

void MainWindow::dmt_cmd()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = power;
    _srv.request.engineFR = power * -1;
    _srv.request.engineBL = power;
    _srv.request.engineBR = power * -1;
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power;
    params[2] = power *(-1);
    params[3] = power;
    params[4] = power * (-1);
    params[5] = 'd';
     update();
}

void MainWindow::right_cmd()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = (power);
    _srv.request.engineFR = (power /2);
    _srv.request.engineBL = (power);
    _srv.request.engineBR = (power /2);
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power;
    params[2] = (power /2);
    params[3] = power;
    params[4] = (power /2);
    params[5] = 'r';
     update();
}

void MainWindow::on_up_pressed()
{
    //char buf[128];

    _srv.request.action = 'G';
    _srv.request.engineFL = (power);
    _srv.request.engineFR = (power);
    _srv.request.engineBL = (power);
    _srv.request.engineBR = (power);
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power;
    params[2] = power;
    params[3] = power;
    params[4] = power;
    params[5] = 'g';
     update();
    std::cout << "ca rentre" << std::endl;
}

void MainWindow::update()
{
    std::cout << "salut ca rentre" << std::endl;
    char buf[128];
    memset(buf, 0, 128);
    buf[0] = params[0];
    buf[1] = params[1];
    buf[2] = params[2];
    buf[3] = params[3];
    buf[4] = params[4];
    buf[5] = -125;
    buf[6] = params[5];
    buf[7] = '\n';
    //send(fd, buf, 128, 0);

    if (_client.call(_srv))
    {
        std::cout << "HERE" << std::endl;
        ROS_INFO("Sum: %ld", (long int)_srv.response.ret);
    }
    else
    {
        std::cout << "FAIL" << std::endl;
        ROS_ERROR("Failed to call service add_two_ints");
    }
    std::cout << "ca marche très bien" << std::endl;
}

void MainWindow::on_left_pressed()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = (power /2);
    _srv.request.engineFR = power;
    _srv.request.engineBL = (power /2);
    _srv.request.engineBR = power;
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = (power /2);
    params[2] = power;
    params[3] = (power /2);
    params[4] = power;
    params[5] = 'l';
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void MainWindow::on_right_pressed()
{
    std::cout << "right pressed" << std::endl;
    _srv.request.action = 'G';
    _srv.request.engineFL = (power);
    _srv.request.engineFR = (power /2);
    _srv.request.engineBL = (power);
    _srv.request.engineBR = (power /2);
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power;
    params[2] = (power /2);
    params[3] = power;
    params[4] = (power /2);
    params[5] = 'r';
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}


void MainWindow::on_down_pressed()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = (power *-1);
    _srv.request.engineFR = (power *-1);
    _srv.request.engineBL = (power *-1);
    _srv.request.engineBR = (power *-1);
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power * (-1);
    params[2] = power * (-1);
    params[3] = power * (-1);
    params[4] = power *(-1);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void MainWindow::on_dtg_pressed()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = (power *-1);
    _srv.request.engineFR = (power);
    _srv.request.engineBL = (power *-1);
    _srv.request.engineBR = (power);
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power * (-1);
    params[2] = power;
    params[3] = power * (-1);
    params[4] = power;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}


void MainWindow::on_dtd_pressed()
{
    _srv.request.action = 'G';
    _srv.request.engineFL = (power);
    _srv.request.engineFR = (power *-1);
    _srv.request.engineBL = (power);
    _srv.request.engineBR = (power *-1);
    _srv.request.time = 125;

    params[0] = 'G';
    params[1] = power;
    params[2] = power *(-1);
    params[3] = power;
    params[4] = power * (-1);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void MainWindow::on_sliderSpeed_valueChanged(int value)
{
    std::cout << "ca passe"<< std::endl;
    //value = this->ui->sliderSpeed->value();
    power = value;
    std::cout << power << std::endl;
    //std::cout << value << std::endl;
    std::cout << "ca passe aussi"<< std::endl;
}

void MainWindow::on_pushButton_clicked()
{
//    int cmpt;

  //  cmpt = 0;
    up_cmd();
    sleep(1);
    left_cmd();
    sleep(1);
    up_cmd();
    sleep(1);
    right_cmd();
    sleep(1);
    up_cmd();
    on_pause_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{
    left_cmd();
    sleep(1);
    left_cmd();
    up_cmd();
    sleep(1);
    left_cmd();
    sleep(1);
    up_cmd();
    sleep(1);
    right_cmd();
    sleep(1);
    up_cmd();
   on_pause_clicked();
}

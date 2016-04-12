#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
//#include "../Client/HandleConnection.h"
# include <direct.h>
//# include "../Client/Connection_Win.h"

void MainWindow::getDirPath()
{
    char buf[4096];

    memset (buf, 0, 4096);
        _getcwd(buf, 4096);
    std::string fullPath(buf);
            std::cout << fullPath << std::endl;
    unsigned int pos = fullPath.rfind("robotController");
    curPath = fullPath.substr(0, pos + sizeof("robotController"));
    std::cout << curPath << std::endl;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cmdIdx = 0;
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
    iResult = getaddrinfo("10.20.85.231", "4242", &hints, &result);
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
    }
    std::cout << "3" << std::endl;
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
    closesocket(fd);
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
std::cout << "debug" << std::endl;
      if (timer)
       {
           timer->stop();
           timer = NULL;
       }
// timer->stop();
    std::cout << "debug4" << std::endl;
    Sleep(10);
    memset(buf, 0, 128);
    buf[0] = 's';
    buf[1] = ' ';
  buf[2] = ' ';
   buf[3] = ' ';
    buf[4] = ' ';
   //  buf[5] = ' ';
    buf[5] = 's';
    buf[6] = '\n';
    std::cout << "debug1" << std::endl;
    send(fd, buf, 128, 0);
    std::cout << "debug2" << std::endl;
}

void MainWindow::left_cmd()
{
    params[0] = 'G';
    params[1] = (power /2);
    params[2] = power;
    params[3] = (power /2);
    params[4] = power;
    //params[5] = 'l';
     update();
}

void MainWindow::dmt_cmd()
{
    params[0] = 'G';
    params[1] = power;
    params[2] = power *(-1);
    params[3] = power;
    params[4] = power * (-1);
    //params[5] = 'd';
     update();
}

void MainWindow::right_cmd()
{
    params[0] = 'G';
    params[1] = power;
    params[2] = (power /2);
    params[3] = power;
    params[4] = (power /2);
    //params[5] = 'r';
     update();
}

void MainWindow::on_up_pressed()
{
    //char buf[128];

    params[0] = 'G';
    params[1] = power;
    params[2] = power;
    params[3] = power;
    params[4] = power;
    //params[5] = 'g';
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    std::cout << "ca rentre" << std::endl;
}

void MainWindow::update()
{
    std::cout << "salut ca rentre" << std::endl;
    unsigned char buf[128];
    memset(buf, 0, 128);
    buf[0] = params[0];
    buf[1] = params[1];
    buf[2] = params[2];
    buf[3] = params[3];
    buf[4] = params[4];
    buf[5] = 80;
    //buf[6] = params[5];
    buf[6] = '\n';
    std::cout << "Send" << buf << std::endl;
    send(fd, (char*)buf, 128, 0);
    std::cout << "ca marche très bien" << std::endl;
}

void MainWindow::exec_cmd()
{
    std::cout << "exec command"<< std::endl;
    (this->*(cmd[cmdIdx]))();
    ++cmdIdx;
}

void MainWindow::on_left_pressed()
{
    params[0] = 'G';
    params[1] = (power /2);
    params[2] = power;
    params[3] = (power /2);
    params[4] = power;
    //params[5] = 'l';
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void MainWindow::on_right_pressed()
{
    params[0] = 'G';
    params[1] = power;
    params[2] = (power /2);
    params[3] = power;
    params[4] = (power /2);
    //params[5] = 'r';
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}


void MainWindow::on_down_pressed()
{
    params[0] = 'G';
    params[1] = power * (-1);
    params[2] = power * (-1);
    params[3] = power * (-1);
    params[4] = power *(-1);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void MainWindow::dt_cmd()
{
    params[0] = 'G';
    params[1] = power; //* (-1);
    params[2] = power;
    params[3] = power; //* (-1);
    params[4] = power;
     update();
}

void MainWindow::on_dtg_pressed()
{
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
    params[0] = 'G';
    params[1] = power;
    params[2] = power *(-1);
    params[3] = power;
    params[4] = power* (-1);
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
    //int cmpt;

    cmd.push_back(&MainWindow::up_cmd);
    cmd.push_back(&MainWindow::right_cmd);
    cmd.push_back(&MainWindow::up_cmd);

    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(exec_cmd()));
    timer->start(3000);
    if (cmdIdx == cmd.size())
        on_pause_clicked();
   /* cmpt = 0;
    while (cmpt < 6)
      {
        up_cmd();
        Sleep(1000);
        cmpt++;
    }
    //cmpt = 0;
      //      while(cmpt < 2)
        //    {
                right_cmd();
                Sleep(1000);
          //      cmpt++;
            //}

    cmpt = 0;
    while (cmpt < 6)
    {
    up_cmd();
    Sleep(1000);
    cmpt++;
    }
    //up_cmd();
    //Sleep(1000);
    //right_cmd();
    //Sleep(1000);
    //up_cmd();
    on_pause_clicked();*/
}

void MainWindow::on_pushButton_2_clicked()
{
  //cmd.clear();
    //cmdIdx = 0;
   // cmd.push_back(&MainWindow::dt_cmd);
    //cmd.push_back(&MainWindow::up_cmd);
    //cmd.push_back(&MainWindow::left_cmd);
    //cmd.push_back(&MainWindow::up_cmd);

    //timerdt = new QTimer(this);

    //connect(timerdt, SIGNAL(timeout()), this, SLOT(dt_cmd()));
   dt_cmd();
   Sleep(2000);
    //on_pause_clicked();
   // dmt_cmd();
    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);

    /*connect(timer, SIGNAL(timeout()), this, SLOT(exec_cmd()));
    timer->start(3000);
    if (cmdIdx == cmd.size())
        on_pause_clicked();*/


    cmd.push_back(&MainWindow::up_cmd);
    cmd.push_back(&MainWindow::left_cmd);
    cmd.push_back(&MainWindow::up_cmd);

    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(exec_cmd()));
    timer->start(3000);
    if (cmdIdx == cmd.size())
        on_pause_clicked();

    /*int cmpt;

    cmpt = 0;

    dt_cmd();
    Sleep(500);
    dt_cmd();
    //Sleep(500);
    while (cmpt < 7)
      {
        up_cmd();
        Sleep(1000);
        cmpt++;
    }
    //cmpt = 0;
      //      while(cmpt < 2)
        //    {
                left_cmd();
                Sleep(1000);
          //      cmpt++;
            //}
    //left_cmd();
    //Sleep(1000);
    cmpt = 0;
    while (cmpt < 7)
    {
        up_cmd();
        Sleep(1000);
        cmpt++;
        }
        on_pause_clicked();
        /*left_cmd();
        Sleep(1500);
        left_cmd();
        up_cmd();
        Sleep(1500);
        left_cmd();
    Sleep(1500);
    up_cmd();
    Sleep(1500);
    right_cmd();
    Sleep(1500);
    up_cmd();
   on_pause_clicked();*/
}

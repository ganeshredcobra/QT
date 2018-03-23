#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numData = 199;
    timer = new QTimer(this);
    // setup signal and slot
        connect(timer, SIGNAL(timeout()),
              this, SLOT(MyTimerSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    bData.broadcastDatagram(numData);
    timer->start(1000);

}

void MainWindow::MyTimerSlot()
{
    numData++;
    bData.broadcastDatagram(numData);

}

void MainWindow::on_stopButton_clicked()
{

}

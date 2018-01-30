#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(QString::number(0));
    ui->threadincrval->setText(QString::number(0));

    incrBool = false;
    mainIncr=0;

}

MainWindow::~MainWindow()
{
    copyThr=THREADEXIT;
    delete ui;
}

void MainWindow::on_increment_clicked()
{
    if(incrBool==false)
    {
        incrBool=true;
        QFuture<void> copyFeed = QtConcurrent::run(this,&MainWindow::copyThread);
        copyThr=THREADSTART;
        ui->increment->setText("Stop Thread");
    }
    else {
        incrBool=false;
        copyThr=THREADEXIT;
         ui->increment->setText("Copy Thread");
    }
}

void MainWindow::copyThread(void)
{
    int i=0;
      while (copyThr==THREADSTART) {
        i++;
        ui->threadincrval->setText(QString::number(i));
        QThread::sleep(2);
    }

   qDebug()<<"Thread Exit";
}

void MainWindow::on_incrMain_clicked()
{
    mainIncr++;
    ui->label->setText(QString::number(mainIncr));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QNetworkRequest request(QUrl("http://192.168.14.114:5000/data"));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void MainWindow::updateData(void)
{
    QTime current = QTime::currentTime();
    QString timeStamp = current.toString("hh.mm.AP");
    qDebug()<<timeStamp;

    remoteServer.jsonData["Timestamp"] = timeStamp;
    remoteServer.jsonData["Voltage"] = QString::number(randInt(1,24));
    remoteServer.jsonData["Current"] = QString::number(randInt(1,15));
    remoteServer.jsonData["Resistance"] = QString::number(randInt(1,24));
    remoteServer.jsonData["Battery"] = QString::number(randInt(1,24));
    remoteServer.jsonData["Vehicle speed"] = QString::number(randInt(1,250));;
    remoteServer.jsonData["Diagnostic message"] = QString("No DTC");
    remoteServer.jsonData["Engine speed"] = QString::number(randInt(1,5000));
    remoteServer.jsonData["Coolant level"] = QString::number(randInt(1,100));
}

void MainWindow::on_postServer_clicked()
{
    //fillJsondata();
    //postData(request);
    updateData();
    remoteServer.fillJsondata(remoteServer.jsonData);
    remoteServer.postData();
}

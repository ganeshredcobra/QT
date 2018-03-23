#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "senddata.h"
#include "recvdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    senddata bData;
    recvdata rData;
    int numData;
    QTimer *timer;
public slots:
    void MyTimerSlot();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

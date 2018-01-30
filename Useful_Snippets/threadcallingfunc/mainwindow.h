#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

#define THREADEXIT      0
#define THREADSTART     1


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool incrBool;
    bool copyThr;
    int mainIncr;
    void copyThread(void);

private slots:
    void on_increment_clicked();

    void on_incrMain_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

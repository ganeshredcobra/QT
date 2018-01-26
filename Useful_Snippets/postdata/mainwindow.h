#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int randInt(int low, int high);
    void updateData(void);

    server remoteServer;

private slots:

    void on_postServer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

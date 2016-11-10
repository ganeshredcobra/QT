#include "mainwindow.h"
#include <QApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MyThread thread1("A1"),thread2("B1"),thread3("C1");
    thread1.start();
    thread2.start();
    thread3.start();
    w.show();

    return a.exec();
}

#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread thread1("A"), thread2("B"), thread3("C");

    thread1.start(QThread::LowestPriority);
    thread2.start();
    thread3.start(QThread::HighestPriority);

    return a.exec();
}

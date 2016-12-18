
#include <QCoreApplication>
#include <qtconcurrentrun.h>
#include <QThread>

#ifndef QT_NO_CONCURRENT

void myRunFunction(QString name)
{
    for(int i = 0; i <= 5; i++)
    {
        qDebug() << name << " " << i <<
                    "from" << QThread::currentThread();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<void> t1 = QtConcurrent::run(myRunFunction, QString("A"));
    QFuture<void> t2 = QtConcurrent::run(myRunFunction, QString("B"));
    QFuture<void> t3 = QtConcurrent::run(myRunFunction, QString("C"));

    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();

    return a.exec();
}

#else

#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("Qt Concurrent is not yet supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}
#endif

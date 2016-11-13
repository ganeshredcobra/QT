#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // forward slash for directory separator
    QDir dir1("/home/ganesh/Documents");
    QDir dir2("/home/ganesh/New");

    // output: true false
    qDebug() << dir1.exists() << dir2.exists();

    return a.exec();
}

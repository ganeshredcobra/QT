#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "/home/ganesh/QTPATH";
    QString filepath = "/home/ganesh/Downloads";

    // forward slash for directory separator
    QDir dir1("/home/ganesh/Documents");
    QDir dir2("/home/ganesh/New");

    // output: true false
    qDebug() << dir1.exists() << dir2.exists();

    QDir dir3;
    foreach(QFileInfo item, dir3.drives() )
    {
        qDebug() << item.absoluteFilePath();
    }

    QDir dir4(path);
    if(!dir4.exists())
    {
        qDebug() << "Creating " << path << "directory";
        dir4.mkpath(path);
    }
    else
    {
        qDebug() << path << " already exists";
    }

    QDir dir5(filepath);
    foreach(QFileInfo item, dir5.entryInfoList() )
    {
        if(item.isDir())
            qDebug() << "Dir: " << item.absoluteFilePath();
        if(item.isFile())
            qDebug() << "File: " << item.absoluteFilePath();
    }


    return a.exec();
}

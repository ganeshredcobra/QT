#include <QCoreApplication>
#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<int, QString> Hash;

    Hash.insert(1,"A");
    Hash.insert(2,"B");
    Hash[3] = "C";

    foreach(int i, Hash.keys()) qDebug() << Hash[i];

    QHashIterator<int, QString> iter(Hash);

    while(iter.hasNext())
    {
        iter.next();
        qDebug() << iter.key() << " : " << iter.value();
    }

    qDebug()<<"Key "<<Hash.contains(2);

    return a.exec();
}

#include <QCoreApplication>
#include <QLinkedList>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<QString> List;

    List << "A" << "B" << "C";
    List.append("D");
    List.append("E");
    List.append("F");

    foreach(QString s, List) qDebug() << s;

    return a.exec();
}

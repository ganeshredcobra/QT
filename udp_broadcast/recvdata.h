#ifndef RECVDATA_H
#define RECVDATA_H

#include <QObject>
#include <QUdpSocket>

class recvdata : public QObject
{
    Q_OBJECT
public:
    recvdata();

    QUdpSocket *udpSocket;

public slots:
    void processPendingDatagrams();


};

#endif // RECVDATA_H

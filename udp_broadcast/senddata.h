#ifndef SENDDATA_H
#define SENDDATA_H

#include <QObject>
#include <QTimer>
#include <QUdpSocket>
#include <QDebug>

class senddata : public QObject
{
    Q_OBJECT
public:
    senddata();
    int messageNo;
    void broadcastDatagram(int num);

    QUdpSocket *udpSocket;
    QTimer *timer;

};
#endif // SENDDATA_H

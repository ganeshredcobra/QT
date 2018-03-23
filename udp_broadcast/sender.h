#ifndef SENDER_H
#define SENDER_H

#include <QTimer>
#include <QUdpSocket>
#include <QObject>

class sender : public QObject
{
    Q_OBJECT
public:
    sender();
private:
    QUdpSocket *udpSocket;
    QTimer *timer;
    int messageNo;

    void broadcastDatagram(int num);
};

#endif // SENDER_H

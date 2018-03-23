#include "senddata.h"

senddata::senddata()
{
    //timer = new QTimer(this);
    //! [0]
        udpSocket = new QUdpSocket(this);
    //! [0]
        messageNo = 1;
}

void senddata::broadcastDatagram(int num)
{
    QByteArray datagram = "Broadcast message " + QByteArray::number(num);
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 45454);
    ++messageNo;
}

#include "recvdata.h"

recvdata::recvdata()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),
                this, SLOT(processPendingDatagrams()));
}

void recvdata::processPendingDatagrams()
{
//! [2]
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        //statusLabel->setText(tr("Received datagram: \"%1\"")
         //                    .arg(datagram.data()));
        qDebug()<<"Received datagram: "<<datagram.data();
    }
//! [2]
}

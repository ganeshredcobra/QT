#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include <QDateTime>
#include <QDebug>


class server
{
public:
    server();

    void fillJsondata(QJsonObject jsonData);
    void postData(void);

    QJsonObject jsonData;
    QNetworkAccessManager nam;
    QByteArray bytesTopost;

    QUrl serverUrl;
    QString stringUrl = "http://192.168.14.114:5000/data";

    QNetworkRequest request;

};

#endif // SERVER_H

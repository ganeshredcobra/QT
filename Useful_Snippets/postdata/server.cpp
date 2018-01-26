#include "server.h"

server::server()
{
    serverUrl.setUrl(stringUrl);
    request.setUrl(serverUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

}

void server::fillJsondata(QJsonObject jsonData)
{
//    QTime current = QTime::currentTime();
//    QString timeStamp = current.toString("hh.mm.AP");
//    qDebug()<<timeStamp;

//    jsonData["Timestamp"] = timeStamp;
//    jsonData["Voltage"] = QString::number(randInt(1,24));
//    jsonData["Current"] = QString::number(randInt(1,15));
//    jsonData["Resistance"] = QString::number(randInt(1,24));
//    jsonData["Battery"] = QString::number(randInt(1,24));
//    jsonData["Vehicle speed"] = QString::number(randInt(1,250));;
//    jsonData["Diagnostic message"] = QString("test");
//    jsonData["Engine speed"] = QString::number(randInt(1,5000));
//    jsonData["Coolant level"] = QString::number(randInt(1,100));


    QJsonDocument doc(jsonData);
    bytesTopost = doc.toJson();

    qDebug() << bytesTopost;
}

void server::postData(void){
    QNetworkReply *reply = nam.post(request, bytesTopost);



    while(!reply->isFinished())

    {

    qApp->processEvents();

    }


    QByteArray response_data = reply->readAll();

    qDebug() <<"Response data "<<response_data;



    QJsonDocument replyBodyJson = QJsonDocument::fromJson(response_data);
}


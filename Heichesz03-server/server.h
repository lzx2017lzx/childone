#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<tufao-1/Tufao/HttpServer>
#include<tufao-1/Tufao/httpserverrequest.h>
#include<tufao-1/Tufao/httpserverresponse.h>

#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonValue>
#include<QSqlDatabase>
#include<iostream>
using namespace Tufao;
using namespace std;
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

    HttpServer server;
    QSqlDatabase db;
    void onPostReady(HttpServerRequest &request,
                     HttpServerResponse &response);
    QJsonObject reg(const QJsonObject &req);
    QJsonObject login(const QJsonObject &req);
 QJsonObject nearbyDrivers(const QJsonObject&req);
    QString md5(QString arg);
signals:

public slots:
    void onRequestReady(Tufao::HttpServerRequest&request,Tufao::HttpServerResponse&response);
};

#endif // SERVER_H

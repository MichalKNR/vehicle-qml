#ifndef NETMANAGER_H
#define NETMANAGER_H

#include <QtGui>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

class NetManager: public QObject {
    Q_OBJECT
public:
    NetManager(QObject *parent);
    int     connected;
public slots:
    void init();
    bool sendData(QJsonDocument);
    void disconnectFast();
signals:
    void appDataReq(QJsonDocument);
    void serverConnected(bool connected);
private slots:
    void readData();
    void parseData(QString text);
    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketError(QAbstractSocket::SocketError error);
    void settingsComplete();
    void timerTimeout();
    void pingTimerTimeout();
    void reconnect();
private:
    QTcpSocket  *socket;
    quint32     dataSize;
    QTimer      *timer;
    QTimer      *reconnTimer;
    QTimer      *pingTimer;
    int         ping_missed;
    QDateTime   last_ping;

    QString serverIp = "127.0.0.1";
    int serverPort = 1234;
};

#endif // NETMANAGER_H

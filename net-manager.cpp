#include "net-manager.h"

NetManager::NetManager(QObject *parent):QObject(parent) {
    dataSize=0;
    socket=new QTcpSocket(this);
    connected=0;
    ping_missed=0;

    connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(socketError(QAbstractSocket::SocketError)));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readData()));

    timer=new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeout()));

    reconnTimer=new QTimer(this);
    reconnTimer->setSingleShot(true);
    reconnTimer->setInterval(10*1000);
    connect(reconnTimer,SIGNAL(timeout()),this,SLOT(reconnect()));

    pingTimer=new QTimer(this);
    pingTimer->setSingleShot(false);
    pingTimer->setInterval(10*1000);
    connect(pingTimer,SIGNAL(timeout()),this,SLOT(pingTimerTimeout()));
}
void NetManager::init() {
    qDebug()<<"NetManager::init";
    timer->start();
}
void NetManager::timerTimeout() {
    qDebug()<<"NetManager::init serverIp:"<<serverIp<<" serverPort:"<<serverPort;
    socket->connectToHost(serverIp, serverPort);
    reconnTimer->start();
    last_ping=QDateTime::currentDateTime();
}
void NetManager::disconnectFast() {
    if(last_ping.addSecs(20)<QDateTime::currentDateTime()) {
        reconnTimer->setInterval(10);
        socket->disconnectFromHost();
        reconnTimer->stop();
        reconnTimer->start();
    }
}
void NetManager::reconnect() {
    socket->abort();
    socket->connectToHost(serverIp, serverPort);
}
void NetManager::readData() {
    //    qDebug() << "NetManager::readData";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);
    if (dataSize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint32))
            return;
        in >> dataSize;
    }
    if(socket->bytesAvailable() < dataSize)
        return;

    QString text;
    in >> text;
    //    qDebug() << "NetManager::readData bytes:"<<dataSize<<" received:"<<text;
    dataSize=0;
    this->parseData(text);
    if(this->socket->bytesAvailable()) {
        this->readData();
    }
}
void NetManager::parseData(QString text) {
    QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8());
    if(doc.isNull()) {
        qDebug() << "NetManager::parseData parse error text:"<<text;
        return;
    }

    QString type = doc.object().value("type").toString();
    if(type == "request") {
        qDebug().noquote()<<"NetManager::parseData json:"<<doc.toJson();
        emit appDataReq(doc);
    }
    else if (type == "pong") {
        ping_missed=0;
        last_ping=QDateTime::currentDateTime();
    }
    else {
        qDebug().noquote()<<"NetManager::parseData json:"<<doc.toJson();
        qWarning() << "NetManager::parseData unknown type:" << type;
    }
}
void NetManager::settingsComplete() {

}
bool NetManager::sendData(QJsonDocument doc) {
    QString text = doc.toJson();
    if(!connected)
        return false;
    qDebug().noquote() << "NetManager::sendData xmlReq:"<<text;
    QByteArray block;
    QDataStream out(&block, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint32)0;
    out << text;
    out.device()->seek(0);
    out << (quint32)(block.size() - sizeof(quint32));
    if(socket->write(block)==-1) {
        qDebug()<<"NetManager::sendData write failed xml:"<<text;
        return false;
    }
    return true;
}
void NetManager::pingTimerTimeout() {
    if(ping_missed>3) {
        socket->disconnectFromHost();
        return;
    }
    QJsonObject obj;
    obj.insert("type", QJsonValue::fromVariant("ping"));
    this->sendData(QJsonDocument(obj));
    ping_missed++;
}
void NetManager::socketStateChanged(QAbstractSocket::SocketState state) {
    switch(state) {
    case QAbstractSocket::UnconnectedState:
        qDebug() <<"NetManager::socketStateChanged state=unconnected";
        this->connected=0;
        this->reconnTimer->start();
        this->pingTimer->stop();
        emit serverConnected(connected);
        break;
    case QAbstractSocket::HostLookupState:
        qDebug() << "NetManager::socketStateChanged state=host lookup";
        this->connected=0;
        break;
    case QAbstractSocket::ConnectingState:
        qDebug() << "NetManager::socketStateChanged state=connecting";
        this->connected=0;
        break;
    case QAbstractSocket::ConnectedState:
        qDebug() << "NetManager::socketStateChanged state=connected peerName:"<<socket->peerName();
        this->connected=1;
        ping_missed=0;
        reconnTimer->setInterval(10*1000);
        this->reconnTimer->stop();
        this->pingTimer->start();
        emit serverConnected(connected);
        break;
    case QAbstractSocket::ClosingState:
        qDebug() << "NetManager::socketStateChanged state=closing connection";
        this->connected=0;
        break;
    }
}
void NetManager::socketError(QAbstractSocket::SocketError error) {
    switch (error) {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug() << "NetManager::socketError error=remote host closed connection";
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug() << "NetManager::socketError error=host not found";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug() << "NetManager::socketError error=connection refused";
        break;
    default:
        qDebug() << "NetManager::socketError error="<<socket->errorString();
        qDebug()<<"NetManager::socketError peerName:"<<socket->peerName()<<" address:"<<socket->peerAddress().toString();
    }
}

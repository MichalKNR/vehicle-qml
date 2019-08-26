#include "backend.h"

BackEnd::BackEnd(QQmlApplicationEngine* engine)
{
    QString serverIp = "127.0.0.1";
    int serverPort = 1234;

    QString configFileName = "vehicle-qml.conf";
    settings = new QSettings(configFileName, QSettings::IniFormat);
    if (QFileInfo::exists(configFileName) && QFileInfo(configFileName).isFile()) {
        qDebug() << "BackEnd::BackEnd read configFile " << configFileName;

        QString key = "serverIp";
        if (settings->contains(key)) {
            serverIp = settings->value(key).toString();
        } else {
            qDebug() << "BackEnd::BackEnd config file does not contains" << key;
        }

        key = "serverPort";
        if (settings->contains(key)) {
            serverPort = settings->value(key).toInt();
        } else {
            qDebug() << "BackEnd::BackEnd config file does not contains" << key;
        }
    } else {
        qDebug() << "BackEnd::BackEnd configFile " << configFileName << " not found";
    }

    this->engine = engine;

    netManager = new NetManager(this, serverIp, serverPort);
    appData = new AppData(this);

    context = engine->rootContext();
    context->setContextProperty("AppData",appData);

    connect(netManager,SIGNAL(appDataReq(QJsonDocument)),appData,SLOT(newRequest(QJsonDocument)));
    connect(netManager,SIGNAL(serverConnected(bool)),appData,SLOT(setServerConnected(bool)));

    netManager->init();
}

void BackEnd::init() {

}

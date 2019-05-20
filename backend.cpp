#include "backend.h"

BackEnd::BackEnd(QQmlApplicationEngine* engine)
{
    this->engine = engine;

    netManager = new NetManager(this);
    appData = new AppData(this);

    context = engine->rootContext();
    context->setContextProperty("AppData",appData);

    connect(netManager,SIGNAL(appDataReq(QJsonDocument)),appData,SLOT(newRequest(QJsonDocument)));
    connect(netManager,SIGNAL(serverConnected(bool)),appData,SLOT(setServerConnected(bool)));

    netManager->init();
}

void BackEnd::init() {

}

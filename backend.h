#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "net-manager.h"
#include "app-data.h"

class BackEnd: public QObject
{
    Q_OBJECT
public:
    BackEnd(QQmlApplicationEngine* engine);
    void init();

private:
    QQmlApplicationEngine* engine;
    QQmlContext* context;
    NetManager* netManager;
    AppData* appData;
    QSettings* settings;
};

#endif // BACKEND_H

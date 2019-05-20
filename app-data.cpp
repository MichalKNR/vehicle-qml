#include "app-data.h"


AppData::AppData(QObject* parent) : QObject (parent)
{
}

void AppData::newRequest(QJsonDocument doc) {
    qDebug() << "AppData::newRequest";
    QString valueId = doc.object().value("valueId").toString();
    if (valueId == "Speed") {
        m_value_speed = doc.object().value("value").toInt();
        qDebug() << "m_value_speed" << m_value_speed;
        emit valueSpeedChanged();
    } else if (valueId == "SteerTemperature") {
        valueSteerTemperature = doc.object().value("value").toInt();
    } else if (valueId == "SteerAccurancy") {
        valueSteerAccurancy = doc.object().value("value").toInt();
    } else if (valueId == "EngineTemperature") {
        valueEngineTemperature = doc.object().value("value").toInt();
    } else if (valueId == "EngineAccurancy") {
        valueEngineAccurancy = doc.object().value("value").toInt();
    } else {
        qDebug() << "AppData::newRequest unknown valueId" << valueId;
    }
    emit updateView();
}

void AppData::setServerConnected(bool connected) {
    qDebug() << "server connected = " << connected;
    m_server_connected = connected;
}

int AppData::getValueSpeed() {
    return m_value_speed;
}

int AppData::getValueSteerTemperature() {
    return valueSteerTemperature;
}

int AppData::getValueSteerAccurancy() {
    return valueSteerAccurancy;
}

int AppData::getValueEngineTemperature() {
    return valueEngineTemperature;
}

int AppData::getValueEngineAccurancy() {
    return valueEngineAccurancy;
}

#include "app-data.h"


AppData::AppData(QObject* parent) : QObject (parent)
{
}

void AppData::newRequest(QJsonDocument doc) {
    QString valueId = doc.object().value("valueId").toString();
    qDebug() << "AppData::newRequest" << valueId;
    if (valueId == "Speed") {
        m_value_speed = doc.object().value("value").toInt();
        qDebug() << "m_value_speed" << m_value_speed;
        emit valueSpeedChanged();
    } else if (valueId == "SteerTemperature") {
        m_valueSteerTemperature = doc.object().value("value").toInt();
        emit valueSteerTemperatureChanged();
    } else if (valueId == "SteerAccurancy") {
        m_valueSteerAccurancy = doc.object().value("value").toInt();
        emit valueSteerAccurancyChanged();
    } else if (valueId == "EngineTemperature") {
        m_valueEngineTemperature = doc.object().value("value").toInt();
        emit valueEngineTemperatureChanged();
    } else if (valueId == "EngineAccurancy") {
        m_valueEngineAccurancy = doc.object().value("value").toInt();
        emit valueEngineAccuranacyChanged();
    } else {
        qDebug() << "AppData::newRequest unknown valueId" << valueId;
    }
    emit updateView();
}

void AppData::setServerConnected(bool connected) {
    qDebug() << "server connected = " << connected;
    m_server_connected = connected;
    emit serverConnectedChanged();
}

int AppData::getValueSpeed() {
    return m_value_speed;
}

int AppData::getValueSteerTemperature() {
    return m_valueSteerTemperature;
}

int AppData::getValueSteerAccurancy() {
    return m_valueSteerAccurancy;
}

int AppData::getValueEngineTemperature() {
    return m_valueEngineTemperature;
}

int AppData::getValueEngineAccurancy() {
    return m_valueEngineAccurancy;
}

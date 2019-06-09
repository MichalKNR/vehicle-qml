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
    } else if (valueId == "BatteryTemperature") {
        m_valueBatteryTemperature = doc.object().value("value").toInt();
        emit valueBatteryTemperatureChanged();
    } else if (valueId == "BatteryAccurancy") {
        m_valueBatteryAccurancy = doc.object().value("value").toInt();
        emit valueBatteryAccuranacyChanged();
    } else if (valueId == "BatteryPercent") {
        m_valueBatteryPercent = doc.object().value("value").toInt();
        emit valueBatteryPercentChanged();

    } else if (valueId == "UnderLightsOn") {
        m_valueUnderLightsOn = doc.object().value("value").toBool();
        emit valueUnderLightsOnChanged();

    } else if (valueId == "CheckEngineOn") {
        m_valueCheckEngineOn = doc.object().value("value").toBool();
        emit valueCheckEngineOnChanged();

    } else if (valueId == "AlarmOn") {
        m_valueAlarmOn = doc.object().value("value").toBool();
        emit valueAlarmOnChanged();

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

#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QJsonDocument>
#include <QtCore>

class AppData : public QObject
{
    Q_OBJECT
public:
    AppData(QObject* parent);

    Q_PROPERTY(bool server_connected MEMBER m_server_connected NOTIFY serverConnectedChanged)
    Q_PROPERTY(int value_speed MEMBER m_value_speed NOTIFY valueSpeedChanged)
    Q_PROPERTY(int valueSteerTemperature MEMBER m_valueSteerTemperature NOTIFY valueSteerTemperatureChanged)
    Q_PROPERTY(int valueSteerAccurancy MEMBER m_valueSteerAccurancy NOTIFY valueSteerAccurancyChanged)
    Q_PROPERTY(int valueEngineTemperature MEMBER m_valueEngineTemperature NOTIFY valueEngineTemperatureChanged)
    Q_PROPERTY(int valueEngineAccurancy MEMBER m_valueEngineAccurancy NOTIFY valueEngineAccuranacyChanged)
    Q_PROPERTY(int valueBatteryTemperature MEMBER m_valueBatteryTemperature NOTIFY valueBatteryTemperatureChanged)
    Q_PROPERTY(int valueBatteryAccurancy MEMBER m_valueBatteryAccurancy NOTIFY valueBatteryAccuranacyChanged)
    Q_PROPERTY(int valueBatteryPercent MEMBER m_valueBatteryPercent NOTIFY valueBatteryPercentChanged)
    Q_PROPERTY(bool valueUnderLightsOn MEMBER m_valueUnderLightsOn NOTIFY valueUnderLightsOnChanged)
    Q_PROPERTY(bool valueCheckEngineOn MEMBER m_valueCheckEngineOn NOTIFY valueCheckEngineOnChanged)
    Q_PROPERTY(bool valueAlarmOn MEMBER m_valueAlarmOn NOTIFY valueAlarmOnChanged)

signals:
    void updateView();
    /* Q_PROPERTY */
    void serverConnectedChanged();
    void valueSpeedChanged();
    void valueSteerTemperatureChanged();
    void valueSteerAccurancyChanged();
    void valueEngineTemperatureChanged();
    void valueEngineAccuranacyChanged();
    void valueBatteryTemperatureChanged();
    void valueBatteryAccuranacyChanged();
    void valueBatteryPercentChanged();
    void valueUnderLightsOnChanged();
    void valueCheckEngineOnChanged();
    void valueAlarmOnChanged();
public slots:
    void setServerConnected(bool connected);
    void newRequest(QJsonDocument);
private:
    bool m_server_connected = false;
    int m_value_speed;
    int m_valueSteerTemperature;
    int m_valueSteerAccurancy;
    int m_valueEngineTemperature;
    int m_valueEngineAccurancy;
    int m_valueBatteryTemperature;
    int m_valueBatteryAccurancy;
    int m_valueBatteryPercent;

    bool m_valueUnderLightsOn;
    bool m_valueCheckEngineOn;
    bool m_valueAlarmOn;
};

#endif // APPDATA_H

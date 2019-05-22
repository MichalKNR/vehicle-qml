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



    int getValueSpeed();
    int getValueSteerTemperature();
    int getValueSteerAccurancy();
    int getValueEngineTemperature();
    int getValueEngineAccurancy();
signals:
    void updateView();
    /* Q_PROPERTY */
    void serverConnectedChanged();
    void valueSpeedChanged();
    void valueSteerTemperatureChanged();
    void valueSteerAccurancyChanged();
    void valueEngineTemperatureChanged();
    void valueEngineAccuranacyChanged();
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
};

#endif // APPDATA_H

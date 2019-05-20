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

    int getValueSpeed();
    int getValueSteerTemperature();
    int getValueSteerAccurancy();
    int getValueEngineTemperature();
    int getValueEngineAccurancy();
signals:
    void updateView();
    void serverConnectedChanged();
    void valueSpeedChanged();
public slots:
    void setServerConnected(bool connected);
    void newRequest(QJsonDocument);
private:
    bool m_server_connected;
    int m_value_speed;
    int valueSteerTemperature;
    int valueSteerAccurancy;
    int valueEngineTemperature;
    int valueEngineAccurancy;
};

#endif // APPDATA_H

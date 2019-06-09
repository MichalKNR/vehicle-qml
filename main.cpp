#include <QApplication>
#include <QQmlApplicationEngine>
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QQmlApplicationEngine engine;

    BackEnd backEnd(&engine);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    return a.exec();
}

#include <QCoreApplication>
#include <QNetworkInterface>
#include <QDebug>
#include <QTimer>
#include <ethernetwatcher.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EthernetWatcher watcher;
    watcher.setIp(QHostAddress("192.168.0.35"));
    watcher.start();
    watcher.watch();
    QObject::connect(&watcher, &EthernetWatcher::cableConnected, []() {
        qDebug()<<"plugin";

    });
    QObject::connect(&watcher, &EthernetWatcher::cableDisconnected, []() {
        qDebug()<<"un plug";

    });
    return a.exec();
}

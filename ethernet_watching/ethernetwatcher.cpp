#include "ethernetwatcher.h"

EthernetWatcher::EthernetWatcher(QObject *parent)
    : QObject{parent}
{

}

const QHostAddress &EthernetWatcher::getIp() const
{
    return ip;
}

void EthernetWatcher::setIp(const QHostAddress &newIp)
{
    ip = newIp;
}

void EthernetWatcher::start()
{
    timer.start(1000);
}

void EthernetWatcher::stop()
{
    timer.stop();
}

void EthernetWatcher::watch()
{
    QObject::connect(&timer, &QTimer::timeout, [this]() {
        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        foreach(const QNetworkInterface & interface, interfaces)
        {
            if (interface.flags() & QNetworkInterface::IsUp){
                QList<QNetworkAddressEntry> address = interface.addressEntries();
                foreach (QNetworkAddressEntry adrs, address) {
                    if(adrs.ip() == getIp())
                        emit cableConnected();
                }
            }else{
                QList<QNetworkAddressEntry> address = interface.addressEntries();
                foreach (QNetworkAddressEntry adrs, address) {
                    if(adrs.ip() == getIp())
                        emit cableDisconnected();
                }
            }
        }

    });
}

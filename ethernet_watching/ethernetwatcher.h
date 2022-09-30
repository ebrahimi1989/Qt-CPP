#ifndef ETHERNETWATCHER_H
#define ETHERNETWATCHER_H

#include <QObject>
#include <QNetworkInterface>
#include <QDebug>
#include <QTimer>
class EthernetWatcher : public QObject
{
    Q_OBJECT
public:
    explicit EthernetWatcher(QObject *parent = nullptr);

    const QHostAddress &getIp() const;
    void setIp(const QHostAddress &newIp);

public slots:
    void start();
    void stop();
    void watch();
signals:
    void cableConnected();
    void cableDisconnected();
private:
    QHostAddress ip;
    QTimer timer;
};

#endif // ETHERNETWATCHER_H

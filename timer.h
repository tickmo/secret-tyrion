#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QSettings>
#include <QTime>
#include <QPixmap>
#include <QByteArray>
#include <QTime>
#include <QApplication>
#include <QDir>
#include <QScreen>
#include <QPixmap>
#include <QDateTime>
#include <QTemporaryDir>
#include <QUrlQuery>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QUrlQuery>
#include <QUrl>
#include <QByteArray>
#include <QFile>

#include "imguploader.h"
#include "mainimage.h"

class Timer : public QTimer
{
    Q_OBJECT

public:
    explicit Timer(imgUploader *imageUploader, MainImage *mainImage, QObject *parent = 0);
    bool active();
    void run();
    void pause();
    void toggle();

private slots:
    void tick();

private:
    bool running;
    QTime nextSyncTime;
    static const int INTERVAL = 3 * 60;
    void increaseInterval();
    void save(QPixmap pixmap);
    void shoot();
    QPixmap originalPixmap;
    QTemporaryDir tempDir;
    imgUploader *uploader;
    MainImage *image;
};

#endif // TIMER_H

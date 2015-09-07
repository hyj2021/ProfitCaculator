#ifndef FUTUREDATECRAWLER_H
#define FUTUREDATECRAWLER_H

#include <QObject>
#include <QtNetwork>
#include <QtCore>
#include <QEventLoop>
#include "futuredata.h"
class QNetworkReply;

class NetWorker : QObject
{
    Q_OBJECT
public:
    static NetWorker* instance();
    ~NetWorker();
    QByteArray get(const QString &url);//只负责抓取页面
    FutureData getLatestData(const QString& productCode);//获取最新的信息，需要单独处理
    QList<FutureData> getHistoricalData(const QDate& start, const QDate& end);//获取历史的数据，可以用jason处理

signals:
    void finished(QNetworkReply* reply);
private:
    class Private;
    friend class Private;
    Private* d;

    explicit NetWorker(QObject* parent = 0);
    NetWorker(const NetWorker&) Q_DECL_EQ_DELETE;//C++11 forbid copy constructor
    NetWorker& operator= (const NetWorker& rhs) Q_DECL_EQ_DELETE;//C++ 11 forbid copy constructor
};

#endif // FUTUREDATECRAWLER_H

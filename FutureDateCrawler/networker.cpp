#include "networker.h"
//单例模式
//内部类,要先定义

class QNetworkReply;
class NetWorker::Private
{
public:
    //传入指针，使其成为QNetWorkAccessManager的parent，可以自动析构
    Private(NetWorker *q) : manager(new QNetworkAccessManager(q))
    {
    }
    QNetworkAccessManager* manager;
};

NetWorker *NetWorker::instance()
{
    static NetWorker netWorker;
    return &netWorker;
}
NetWorker::NetWorker(QObject* parent) :
    QObject(parent),
    d(new NetWorker::Private(this))
{
    //connect(d->manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));//信号转发
    //connect(d->manager, &QNetworkAccessManager::finished, this, &NetWorker::finished);
}

NetWorker::~NetWorker()
{
    delete d;
    d = 0;
}
QByteArray NetWorker::get(const QString& url)
{
    QEventLoop eventLoop;
    connect(d->manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkReply* reply = d->manager->get(QNetworkRequest(QUrl(url)));
    //connect(this, &NetWorker::finished, &eventLoop, &QEventLoop::quit);//抓取结束才结束事件循环
    //connect(this, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    //获取html代码
    QByteArray responseData = reply->readAll();
    reply->deleteLater();
    return responseData;
}
FutureData NetWorker::getLatestData(const QString &productCode)
{
    QString url = "http://hq.sinajs.cn/list=" + productCode;
    QByteArray responseData = get(url);
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QString html = codec->toUnicode(responseData);
    //对ResponseData进行解析
    int startIndex = html.indexOf("\"");
    int endIndex = html.indexOf(";");
    QString tmpString = html.mid(startIndex+1, endIndex - startIndex-2);
    QStringList stringList = tmpString.split(",");
    FutureData futureData;
    futureData.setName(stringList.at(0));
    futureData.setSupplier(stringList.at(1));
    QString openStr = stringList.at(2);
    futureData.setOpen(openStr.toDouble());
    QString highestStr = stringList.at(3);
    futureData.setHighest(highestStr.toDouble());
    QString lowestStr = stringList.at(4);
    futureData.setLowest(lowestStr.toDouble());
    QString lastCloseStr = stringList.at(5);
    futureData.setLastClose(lastCloseStr.toDouble());
    QString buyStr = stringList.at(6);
    futureData.setBuy(buyStr.toDouble());
    QString sellStr = stringList.at(7);
    futureData.setSell(sellStr.toDouble());
    QString latestStr = stringList.at(8);
    futureData.setLatest(latestStr.toDouble());
    QString settlementStr = stringList.at(9);
    futureData.setSettlement(settlementStr.toDouble());
    QString lastSettlementStr = stringList.at(10);
    futureData.setLastSettlement(lastSettlementStr.toDouble());
    QString buyAmountStr = stringList.at(11);
    futureData.setBuyAmount(buyAmountStr.toDouble());
    QString sellAmountStr = stringList.at(12);
    futureData.setSellAmount(sellAmountStr.toDouble());
    QString holdStr = stringList.at(13);
    futureData.setHold(holdStr.toDouble());
    QString volStr = stringList.at(14);
    futureData.setVol(volStr.toDouble());
    futureData.setExchange(stringList.at(15));
    futureData.setShortName(stringList.at(16));
    futureData.setDate(stringList.at(17));
    return futureData;
}




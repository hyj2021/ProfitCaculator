#ifndef FUTUREDATA_H
#define FUTUREDATA_H

#include <QObject>

class FutureData
{
public:
    QString getName() const;
    void setName(const QString &value);

    QString getSupplier() const;
    void setSupplier(const QString &value);

    double getOpen() const;
    void setOpen(double value);

    double getHighest() const;
    void setHighest(double value);

    double getLowest() const;
    void setLowest(double value);

    double getLastClose() const;
    void setLastClose(double value);

    double getBuy() const;
    void setBuy(double value);

    double getSell() const;
    void setSell(double value);

    double getLatest() const;
    void setLatest(double value);

    double getSettlement() const;
    void setSettlement(double value);

    double getLastSettlement() const;
    void setLastSettlement(double value);

    double getBuyAmount() const;
    void setBuyAmount(double value);

    double getSellAmount() const;
    void setSellAmount(double value);

    double getHold() const;
    void setHold(double value);

    double getVol() const;
    void setVol(double value);

    QString getExchange() const;
    void setExchange(const QString &value);

    QString getShortName() const;
    void setShortName(const QString &value);

    QString getDate() const;
    void setDate(const QString &value);

private:
    //0：豆粕连续，名字
    QString name;
    //1：145958，不明数字（难道是数据提供商代码？）
    QString supplier;
    //2：3170，开盘价
    double open;
    //3：3190，最高价
    double highest;
    //4：3145，最低价
    double lowest;
    //5：3178，昨日收盘价 （2013年6月27日）
    double lastClose;
    //6：3153，买价，即“买一”报价
    double buy;
    //7：3154，卖价，即“卖一”报价
    double sell;
    //8：3154，最新价，即收盘价
    double latest;
    //9：3162，结算价
    double settlement;
    //10：3169，昨结算
    double lastSettlement;
    //11：1325，买  量
    double buyAmount;
    //12：223，卖  量
    double sellAmount;
    //13：1371608，持仓量
    double hold;
    //14：1611074，成交量
    double vol;
    //15：连，大连商品交易所简称
    QString exchange;
    //16：豆粕，品种名简称
    QString shortName;
    //17：2013-06-28，日期
    QString date;
signals:

public slots:
};

#endif // FUTUREDATA_H

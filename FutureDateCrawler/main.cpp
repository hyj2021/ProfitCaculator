#include <QCoreApplication>
#include "networker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetWorker* netWorker = NetWorker::instance();
    FutureData futureData = netWorker->getLatestData("M0");
    return a.exec();
}

#include "MainWindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QTranslator>
#include "ZZLogWidget/ZZLogMessage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 设置应用程序样式代码
    QStyle *style = QStyleFactory::create("fusion");  // windows,windowsvista,fusion
    a.setStyle(style);

    //安装消息器
    ZZLogMessage::Instance()->installMessageHandler();
    QDEBUG("启动日志系统");

    //设置翻译器
    QTranslator* pTranslator = new QTranslator();
    pTranslator->load(":/Resouce/translate/language_ch.qm");
    a.installTranslator(pTranslator);

    MainWindow w;
    w.show();
    return a.exec();
}

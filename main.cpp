// File: main.cpp
#include <QApplication>
#include <QTextCodec> // 新增头文件
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    
    QApplication a(argc, argv);

    // ========= 新增编码设置 =========
#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    // ==============================

    MainWindow w;
    w.show();
    return a.exec();
}
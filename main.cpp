// File: main.cpp
#include <QApplication>
#include <QTextCodec> // ����ͷ�ļ�
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    
    QApplication a(argc, argv);

    // ========= ������������ =========
#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    // ==============================

    MainWindow w;
    w.show();
    return a.exec();
}
#include <QApplication>
#include "mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <QTextCodec>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
   // QTextCodec::setCodecForCStrings("CP1251");
    QTextCodec::setCodecForTr( QTextCodec::codecForName("CP1251"));

    w.setFixedSize(w.geometry().width(),w.geometry().height());




    w.show();
    
    return a.exec();
}

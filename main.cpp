#include <QApplication>
#include <QFile>
#include <QTranslator>

#include "GlobalData.h"
#include "Start_Window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);
    a.setWindowIcon(QIcon(":/Icons/Icons/app_icon.ico"));  // set mission bar game icon and window icon

    //    QTranslator translator;
    //    translator.load(":/Translation/Chinese_Translation.qm");
    //    GlobalData::GetInstance().app->installTranslator(&translator);

    QFont f("Consolas", 12, 50);
    a.setFont(f);

    Start_Window w;
    w.show();

    return a.exec();
}

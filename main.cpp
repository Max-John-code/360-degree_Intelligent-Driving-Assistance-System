#include "view/bootwidget.h"
#include <QApplication>

#include "view/mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BootWidget w;
    w.show();
//    MainWidget m;
//    m.show();

    return a.exec();
}

#include "jrdgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JrdGui w;
    w.show();

    return a.exec();
}

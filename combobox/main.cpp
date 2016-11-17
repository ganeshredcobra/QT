#include "combobox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    combobox w;
    w.show();

    return a.exec();
}

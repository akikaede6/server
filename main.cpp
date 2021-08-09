#include "client.h"
#include "store.h"

#include <QApplication>
#include <QtDBus>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client w;
    w.show();
    return a.exec();
}

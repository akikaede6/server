#include "client.h"
#include "store.h"

#include <QApplication>
#include <QtDBus>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client w;
    w.show();
//    GSettings *gs;
//    gstring name, phone, id, address;
//    gint age;
//    gdouble temp;

//    gs = gsettings_new("org.healthy");


    return a.exec();


}

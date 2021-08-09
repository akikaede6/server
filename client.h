#ifndef CLIENT_H
#define CLIENT_H
#include "store.h"

#include <QMainWindow>
#include <QtDBus>
#include <QValidator>

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    void setend(QDBusReply<int> _end);
    static int getend();
    store text;

private:
    Ui::client *ui;

public slots:
    void btn_slot();

private:
    QString name = "test";
    int age = 0;
    QString telephone;
    QString idnumber;
    QString address;
    double tempure = 0;
    static QDBusReply<int> end;
//    QValidator *validator = new QRegExpValidator;
//    QValidator *validatora = new QRegExpValidator;
};

inline QDBusReply<int> client::end;

#endif // CLIENT_H

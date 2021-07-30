#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtDBus>

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    QString getName();
    int getAge();
    QString getTelephone();
    QString getIdnumber();
    QString getAddress();
    double getTempure();
    void setend(QDBusReply<bool> end);
    bool getend();

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
    QDBusReply<bool> end;
};

#endif // CLIENT_H

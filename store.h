#ifndef STORE_H
#define STORE_H
#include <QObject>

class store : public QObject
{
    Q_OBJECT

public slots:
    void setname(QString name);
    void setage(int age);
    void setphone(QString telephone);
    void setid(QString idnumber);
    void setaddress(QString address);
    void settempure(double tempure);
    QString getName();
    int getAge();
    QString getTelephone();
    QString getIdnumber();
    QString getAddress();
    double getTempure();

public:
    QString name = "test";
    int age = 0;
    QString telephone;
    QString idnumber;
    QString address;
    double tempure;
};


#endif // STORE_H

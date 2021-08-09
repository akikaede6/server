#include "store.h"
#include <QString>
#include <QDebug>

void store::setname(QString name) {
    this->name = name;
}

void store::setage(int age) {
    this->age = age;
}

void store::setphone(QString telephone) {
    this->telephone = telephone;
}

void store::setid(QString idnumber) {
    this->idnumber = idnumber;
}

void store::setaddress(QString address) {
    this->address = address;
}

void store::settempure(double tempure) {
    this->tempure = tempure;
}

QString store::getName() {
    return name;
}

int store::getAge() {
    return age;
}

QString store::getTelephone() {
    return telephone;
}

QString store::getIdnumber() {
    return idnumber;
}

QString store::getAddress() {
    return address;
}

double store::getTempure() {
    return tempure;
}

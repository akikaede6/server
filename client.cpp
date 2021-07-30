#include "client.h"
#include "ui_client.h"
#include "store.h"
#include "draw.h"

#include <QDebug>
#include <QtDBus>
#include <QWidget>
#include <QHBoxLayout>
#include <QTableView>

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    connect(ui->ok, SIGNAL(clicked()),this,SLOT(btn_slot()));
}


client::~client()
{
    delete ui;
}

void client::btn_slot()
{
    store text;
    text.setname(ui->name->text());
    text.setage(QString(ui->age->text()).toInt());
    text.setphone(ui->phone->text());
    text.setid(ui->id->text());
    text.setaddress(ui->address->text());
    text.settempure(QString(ui->tempture->text()).toDouble());
    qInfo() << text.getName() << text.getAge() << text.getTelephone() << text.getAddress() << text.getIdnumber() << text.getTempure();
    QDBusInterface interface("org.healthy", "/healthy/text", "org.healthy.text");
    client judge;
    drawgreen color;
    if (interface.isValid()) {
        judge.setend(interface.call("setarg", text.getName(), text.getAge(), text.getTelephone(), text.getIdnumber(), text.getAddress(), text.getTempure()));
        qInfo() << judge.getend();
        if (judge.getend()) {
            ui->safe->setText("pass");
            drawgreen *temp = new drawgreen;
            ui->layout->addWidget(temp);
        }
        else {
            ui->safe->setText("danguous!");
            drawred *temp = new drawred;
            ui->layout->addWidget(temp);
        }
    }
}



void client::setend(QDBusReply<bool> end) {
    this->end = end;
}

bool client::getend() {
    return end;
}


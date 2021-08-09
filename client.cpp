#include "client.h"
#include "ui_client.h"
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
    ui->age->setValidator(new QIntValidator(0, 200, this));
    ui->tempture->setValidator(new QDoubleValidator(34.00, 42.00, 2, this));
    QRegExp regx("[1-9][0-9]+$");
    QRegExp regxa("[1-9][0-9]+[X0-9]$");
    QValidator *validator = new QRegExpValidator(regx, ui->phone);
    QValidator *validatora = new QRegExpValidator(regxa, ui->id);
    ui->phone->setValidator(validator);
    ui->id->setValidator(validatora);

    connect(ui->ok, SIGNAL(clicked()),this,SLOT(btn_slot()));

    draw *color = new draw;
    ui->layout->addWidget(color);
}

client::~client()
{
    delete ui;
}

void client::btn_slot()
{
    text.setname(ui->name->text());
    text.setage(QString(ui->age->text()).toInt());
    text.setphone(ui->phone->text());
    text.setid(ui->id->text());
    text.setaddress(ui->address->text());
    text.settempure(QString(ui->tempture->text()).toDouble());
//    qInfo() << text.getName() << text.getAge() << text.getTelephone() << text.getAddress() << text.getIdnumber() << text.getTempure();
    QDBusInterface interface("org.healthy", "/healthy/text", "org.healthy.text");
    if (interface.isValid()) {
        setend(interface.call("setarg", text.getName(), text.getAge(), text.getTelephone(), text.getIdnumber(), text.getAddress(), text.getTempure()));
        if (getend() == 1) {
            ui->safe->setText("pass");
        }
        else if (getend() == 2){
            ui->safe->setText("danguous!");
        }
        else if (getend() == 3) {
            ui->safe->setText("Fail to sotre,\n age invaild!");
        }
        else if (getend() == 4) {
            ui->safe->setText("Fail to sotre,\n tempture invaild!");
        }
        else if (getend() == 5) {
            ui->safe->setText("Fail to store,\n telephone invaild!");
        }
        else if (getend() == 6) {
            ui->safe->setText("Fail to store,\n id invalid!");
        }
    }
}

void client::setend(QDBusReply<int> _end) {
    end = _end;
}

int client::getend() {
    return end;
}

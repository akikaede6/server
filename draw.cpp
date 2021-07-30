#include "draw.h"
#include "client.h"
#include "store.h"

void drawred::paintEvent(QPaintEvent *) {
    QPainter *painter = new QPainter(this);
    painter->setPen(QPen(Qt::red, 2));
    painter->setBrush(QBrush(Qt::red));
    painter->drawRoundedRect(QRect(10,0,20,150), 10, 10);
    painter->setPen(QPen(Qt::red, 2));
    painter->drawEllipse(0, 140, 40, 40);
    painter->end();
}

void drawgreen::paintEvent(QPaintEvent *) {
    QPainter *painter = new QPainter(this);
    painter->setPen(QPen(Qt::green, 2));
    painter->setBrush(QBrush(Qt::green));
    painter->drawRoundedRect(QRect(10,0,20,150), 10, 10);
    painter->setPen(QPen(Qt::green, 2));
    painter->drawEllipse(0, 140, 40, 40);
    painter->end();
}

void drawgreen::setcolor(QDBusReply<bool> color) {
    this->color = color;
}

QDBusReply<bool> drawgreen::getcolor() {
    return color;
}

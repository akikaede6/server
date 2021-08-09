#include "draw.h"
#include "client.h"
#include "store.h"

void draw::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setBrush(usebrush(client::getend()));
    painter.drawRoundedRect(QRect(10,0,20,150), 10, 10);
    painter.drawEllipse(0, 140, 40, 40);
//    qInfo() << client::getend();
    painter.end();
}

QColor draw::usebrush(int release) {
    if (release == 1) {
        return Qt::green;
    }
    else if (release == 2) {
        return Qt::red;
    }
    else {
        return Qt::white;
    }
}

draw::~draw()
{
}

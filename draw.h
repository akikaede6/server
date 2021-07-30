#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QtDBus>


class drawred : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);
};

class drawgreen : public QWidget
{
    Q_OBJECT

public:
    void setcolor(QDBusReply<bool> color);
    QDBusReply<bool> getcolor();

protected:
    void paintEvent(QPaintEvent *);

private:
    QDBusReply<bool> color;
};

#endif // DRAW_H

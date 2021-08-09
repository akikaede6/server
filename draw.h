#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QtDBus>

class draw : public QWidget
{
    Q_OBJECT

public:
    QColor usebrush(int release);
    ~draw();

protected:
    void paintEvent(QPaintEvent *);

private:
    int release = 2;
//    QPainter *painter;
};

#endif // DRAW_H

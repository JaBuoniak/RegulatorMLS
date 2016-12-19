#ifndef KULKA_H
#define KULKA_H

#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Kulka : public QGraphicsItem
{



public:
    QRectF boundingRect() const{
        return QRectF(-150, 0, 300, 300);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    Kulka();
};

#endif // KULKA_H


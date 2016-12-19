#ifndef PODSTAWKA_H
#define PODSTAWKA_H

#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Podstawka : public QGraphicsItem
{
public:
    Podstawka();

    QRectF boundingRect() const{
        return QRectF(-50, 210, 100, 100);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};

#endif // PODSTAWKA_H

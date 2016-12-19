#include "kulka.h"

Kulka::Kulka(){
}

void Kulka::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(-10, -10, 20, 20);
    qreal lod = QStyleOptionGraphicsItem::levelOfDetailFromTransform(painter->worldTransform());
    if(lod >= 5.2)
    {
        painter->setPen(Qt::black);
        painter->drawText(boundingRect(), Qt::AlignCenter, "No PAIN\nno gain");
    }
}



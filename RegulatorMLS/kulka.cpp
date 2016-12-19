#include "kulka.h"

Kulka::Kulka(){
}

void Kulka::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRadialGradient gr(-50, 100, 800, -50, 120);
    gr.setColorAt(0.0, Qt::white);
    gr.setColorAt(0.2, Qt::black);
    gr.setColorAt(0.9, Qt::black);

    painter->setBrush(gr);
    painter->drawEllipse(-150, 0, 300, 300);
}



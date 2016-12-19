#include "podstawka.h"

Podstawka::Podstawka()
{

}

void Podstawka::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLinearGradient gr(-50, 0, 30, 0);
    gr.setColorAt(0.0, Qt::gray);
    gr.setColorAt(0.3, Qt::white);
    gr.setColorAt(0.9, Qt::darkGray);

    painter->setBrush(gr);
    painter->drawRect(-50, 210, 100, 100);
}

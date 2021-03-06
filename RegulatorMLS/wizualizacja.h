#ifndef WIZUALIZACJA_H
#define WIZUALIZACJA_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <kulka.h>
#include <podstawka.h>

class Wizualizacja : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Wizualizacja(QGraphicsScene *parent = 0);

private:
    //wybór kulki: 0 - żadna, 1 - mała, 2 - średnia, 3 - duża
    int nrKulki;
    qreal srednica;
    qreal pozycja;

    QPainter *painter;
    Kulka *kulka;
    Podstawka *podstawka;


public slots:
    void setKulka(int);
    void setKulkaVisible(bool);
    void setKulkaPosition(double);

signals:
    void grafix();



};

#endif // WIZUALIZACJA_H

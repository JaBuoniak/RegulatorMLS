#include <wizualizacja.h>

Wizualizacja::Wizualizacja(QGraphicsScene *parent)
    : QGraphicsScene(parent)
{
    nrKulki = 0;
    srednica = 0;
    pozycja = 0;

    QPen emPen = QPen(Qt::blue);
    QBrush emBrush = QBrush(Qt::darkYellow);
    QPen podstawkaPen = QPen(Qt::black);
    QBrush podstawkaBrush = QBrush(Qt::darkGray);

    addRect(-100, -100, 200, 100, emPen, emBrush);

    kulka = new Kulka();
    addItem(kulka);
    addRect(-50, 200, 100, 100, podstawkaPen, podstawkaBrush);
}

void Wizualizacja::setKulka(int numer){
    nrKulki = numer;
    switch (numer)
    {
        case 1:
            srednica = 42;
            break;

        case 2:
            srednica = 55;
            break;

        case 3:
            srednica = 60;
            break;

        default:
            srednica = 0;
    }

    kulka->setScale((qreal)srednica * 0.01);
}

void Wizualizacja::setKulkaVisible(bool wartosc)
{
    kulka->setVisible(wartosc);
    kulka->advance(1);
}

void Wizualizacja::setKulkaPosition(double wartosc)
{
    pozycja = wartosc * 10;
    kulka->setPos(0, pozycja);
}

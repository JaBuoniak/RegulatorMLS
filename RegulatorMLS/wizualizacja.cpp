#include <wizualizacja.h>

Wizualizacja::Wizualizacja(QGraphicsScene *parent) : QGraphicsScene(parent)
{
    nrKulki = 0;
    srednica = 0;
    pozycja = 0;

    kulka = nullptr;

    QLinearGradient emGradient(-130, 0, 130, 0);
    emGradient.setColorAt(0.0, Qt::yellow);
    emGradient.setColorAt(0.2, Qt::white);
    emGradient.setColorAt(0.3, Qt::darkYellow);
    emGradient.setColorAt(0.7, Qt::darkYellow);
    emGradient.setColorAt(0.9, Qt::white);

    QBrush emBrush = QBrush(emGradient);
    QPen emPen = QPen(Qt::blue);
    QPen blackPen = QPen(Qt::black);
    QBrush blackBrush = QBrush(Qt::black);


    addRect(-100, -100, 200, 100, emPen, emBrush);
    addRect(-140, -25, 10, 90, blackPen, blackBrush);
    addRect(130, -25, 10, 90, blackPen, blackBrush);

    podstawka = new Podstawka();
    addItem(podstawka);
    kulka = new Kulka();
    addItem(kulka);
}

void Wizualizacja::setKulka(int numer){
    nrKulki = numer;
    switch (numer)
    {
        case 1:
            srednica = 42;
            podstawka->setPos(0, -30);
            break;

        case 2:
            srednica = 55;
            podstawka->setPos(0, 30);
            break;

        case 3:
            srednica = 60;
            podstawka->setPos(0, 30);
            break;

        default:
            srednica = 0;
    }

    kulka->setScale(srednica * 0.01);
}

void Wizualizacja::setKulkaVisible(bool wartosc)
{
    kulka->setVisible(wartosc);
}

void Wizualizacja::setKulkaPosition(double wartosc)
{
    pozycja = wartosc * 3;
    kulka->setPos(0, pozycja);
}

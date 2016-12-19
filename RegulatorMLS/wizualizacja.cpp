#include <wizualizacja.h>

Wizualizacja::Wizualizacja(QGraphicsScene *parent)
    : QGraphicsScene(parent)
{
    nrKulki = 0;
    srednica = 0;
    pozycja = 0;

    kulka = new Kulka();
    this->addItem(kulka);

    //kulka->setVisible(false);

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

    kulka->setScale((qreal)srednica / 10);
}

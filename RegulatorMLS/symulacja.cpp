#include <symulacja.h>

#define FPS 10

Symulacja::Symulacja() : QObject(){

    stan = false;
    licznik = 0;
    czas = 60 * FPS;
    kulka = 0;

    parametrP = 300;
    parametrI = 80;
    parametrD = 25;

}

void Symulacja::initialize(QPushButton *startStopButton, QTimer *timer)
{
    sButton = startStopButton;
    sTimer = timer;

    sTimer->setTimerType(Qt::PreciseTimer);
    sTimer->setInterval(1000 / FPS);

    wartoscZadana = 0;

    emit PsliderChanged(parametrP*0.1);
    emit IsliderChanged(parametrI*0.1);
    emit DsliderChanged(parametrD*0.01);
    emit PvalueChanged(parametrP);
    emit IvalueChanged(parametrI);
    emit DvalueChanged(parametrD);
    emit wybierzKulke(false);
    emit kulkaSelected(false);
    emit czasChanged(czas);

}

/* Ustawianie parametrów suwakiem ogranicza się do wartości całkowitych */
void Symulacja::setParametrP(int wartosc){
    parametrP = wartosc;
    emit PsliderChanged(parametrP * 0.1);
}

void Symulacja::setParametrI(int wartosc){
    parametrI = wartosc;
    emit IsliderChanged(parametrI * 0.1);
}

void Symulacja::setParametrD(int wartosc){
    parametrD = wartosc;
    emit DsliderChanged(parametrD * 0.01);
}

/* Ustawianie parametrów liczbą pozwala na podanie dokładnej wartości
 * Emituje sygnał dla suwaka z wartością całkowitą */
void Symulacja::setParametrP(double wartosc){
    parametrP = round(wartosc * 10);
    emit PvalueChanged(parametrP);
}

void Symulacja::setParametrI(double wartosc){
    parametrI = round(wartosc * 10);
    emit IvalueChanged(parametrI);
}

void Symulacja::setParametrD(double wartosc){
    parametrD = round(wartosc * 100);
    emit DvalueChanged(parametrD);
}

/* Wybór kulki - tylko jedna może być wybrana (pola odznaczają się automatycznie)*/
void Symulacja::setMalaKulka(){
    kulka = 1;
    pozycja = 18;
    emit kulkaChanged(kulka);
    emit pozycjaChanged(pozycja);
    emit kulkaSelected(true);
    emit stopSimulation(false);
}

void Symulacja::setSredniaKulka(){
    kulka = 2;
    pozycja = 25;
    emit kulkaChanged(kulka);
    emit pozycjaChanged(pozycja);
    emit kulkaSelected(true);
    emit stopSimulation(false);
}

void Symulacja::setDuzaKulka(){
    kulka = 3;
    pozycja = 20;
    emit kulkaChanged(kulka);
    emit pozycjaChanged(pozycja);
    emit kulkaSelected(true);
    emit stopSimulation(false);
}

/* Zmiana stanu - rozpoczęcie / zakończenie symulacji */
void Symulacja::changeStan(){
    stan = !stan;
    emit stanChanged((int)stan);
}

void Symulacja::setStan(bool wartosc){
    stan = wartosc;
    emit stanChanged((int)stan);
}

void Symulacja::setSimulation(){

    QString text;
    if(stan == true && kulka > 0)
    {
        licznik = 0;
        text = "Stop";
        sButton->setText(text);
        emit startSimulation(0);
        emit wybierzKulke(false);

        szybkosc = 0;
        sterowanie = 0;
        prad = 0;

        poprzedniaPozycja = pozycja;
        calkowanie = 0;

    }
    else
    {
        if(kulka == 0)
            emit wybierzKulke(true);
        stan = false;
        text = "Start";
        sButton->setText(text);
        emit stopSimulation(0);
    }

}

void Symulacja::stepSimulation(){
    if(stan)
    {
        ++licznik;
        emit simulationChanged(licznik);

        /* Obliczenia symulacji */
        double grawitacja = 1.5 - (double)parametrI/80;
        double zaburzenia = (double)(qrand()%20 - 10) / ((double)parametrD);
        double uchyb = wartoscZadana - pozycja;
        poprzedniaPozycja = pozycja;

        if(uchyb < 0)
        {
            sterowanie = -((double)parametrD*32/100) * uchyb / pozycja;
            if(sterowanie > 5)
                sterowanie = 5;
        }
        else
            sterowanie = 0;
        pozycja = pozycja - ((double)parametrP / 300) * sterowanie + grawitacja + zaburzenia;
        if(pozycja <= 0)
            pozycja = 0.1;

        szybkosc = pozycja - poprzedniaPozycja;
        prad = fabs(-sterowanie) * 3;

        emit pozycjaChanged(pozycja);
        emit pozycjaChanged(QString::number(pozycja));
        emit szybkoscChanged(QString::number(szybkosc));
        emit sterowanieChanged(QString::number(sterowanie));
        emit pradChanged(QString::number(prad));
    }
    if(licznik >= czas)
        emit setStan(false);
}

/* Ustawienie czasu trwania symulacji */
void Symulacja::setCzas(int wartosc){
    czas = wartosc * 1000 / FPS;
    emit czasChanged(czas / FPS);
}

/* Zmiana wartości zadanej */
void Symulacja::setWartoscZadana(double wartosc){
    wartoscZadana = wartosc;

}

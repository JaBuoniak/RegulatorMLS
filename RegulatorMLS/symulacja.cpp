#include <symulacja.h>

Symulacja::Symulacja() : QObject(){

    stan = false;
    licznik = 0;
    czas = 60000;
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
    sTimer->setInterval(1);

    emit PsliderChanged(parametrP*0.1);
    emit IsliderChanged(parametrI*0.1);
    emit DsliderChanged(parametrD*0.01);
    emit PvalueChanged(parametrP);
    emit IvalueChanged(parametrI);
    emit DvalueChanged(parametrD);
    emit wybierzKulke(false);
    emit kulkaSelected(false);

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
    emit kulkaChanged(kulka);
    emit kulkaSelected(true);
}

void Symulacja::setSredniaKulka(){
    kulka = 2;
    emit kulkaChanged(kulka);
    emit kulkaSelected(true);
}

void Symulacja::setDuzaKulka(){
    kulka = 3;
    emit kulkaChanged(kulka);
    emit kulkaSelected(true);
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
        emit kulkaPositionChanged(wartoscZadana);
    }
    if(licznik >= czas)
        emit setStan(false);
}

/* Ustawienie czasu trwania symulacji */
void Symulacja::setCzas(int wartosc){
    czas = wartosc * 1000;
    emit czasChanged(czas);
}

/* Zmiana wartości zadanej */
void Symulacja::setWartoscZadana(double wartosc){
    wartoscZadana = wartosc;

}

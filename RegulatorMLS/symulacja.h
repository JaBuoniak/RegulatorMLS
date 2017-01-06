#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QObject>
#include <QPushButton>
#include <QTimer>
#include <cmath>

class Symulacja : public QObject
{
    Q_OBJECT

private:
    bool stan;
    int licznik;
    int czas;
    int kulka;

    double wartoscZadana;
    double pozycja;
    double szybkosc;
    double sterowanie;
    double prad;
    double poprzedniaPozycja;
    double calkowanie;

    int parametrP;
    int parametrI;
    int parametrD;

    QPushButton *sButton;
    QTimer *sTimer;

public:
    Symulacja();
    ~Symulacja(){}

    void initialize(QPushButton *startStopButton, QTimer *timer);

public slots:
    void setParametrP(int);
    void setParametrI(int);
    void setParametrD(int);

    void setParametrP(double);
    void setParametrI(double);
    void setParametrD(double);

    void setMalaKulka();
    void setSredniaKulka();
    void setDuzaKulka();

    void changeStan();
    void setStan(bool);

    void setSimulation();
    void stepSimulation();

    void setCzas(int);
    void setWartoscZadana(double);


signals:
    void stanChanged(int);
    void licznikChanged(int);
    void czasChanged(int);
    void kulkaChanged(int);
    void wybierzKulke(bool);
    void kulkaSelected(bool);

    void startSimulation(int);
    void stopSimulation(int);
    void simulationChanged(int);

    void pozycjaChanged(double);
    void pozycjaChanged(QString);
    void szybkoscChanged(QString);
    void sterowanieChanged(QString);
    void pradChanged(QString);

    void PvalueChanged(int);
    void IvalueChanged(int);
    void DvalueChanged(int);

    void PsliderChanged(double);
    void IsliderChanged(double);
    void DsliderChanged(double);
};

#endif // SYMULACJA_H

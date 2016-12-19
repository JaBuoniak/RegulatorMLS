#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Wizualizacja();
    ui->graphicsViewWizualizacja->setScene(scene);
    ui->graphicsViewWizualizacja->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsViewWizualizacja->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );

    timer = new QTimer();

    simulation = new Symulacja();

    /* Parametr P */
    QObject::connect(ui->horizontalSliderP, SIGNAL(valueChanged(int)), simulation, SLOT(setParametrP(int)));
    QObject::connect(simulation, SIGNAL(PsliderChanged(double)), ui->doubleSpinBoxP, SLOT(setValue(double)));

    QObject::connect(ui->doubleSpinBoxP, SIGNAL(valueChanged(double)), simulation, SLOT(setParametrP(double)));
    QObject::connect(simulation, SIGNAL(PvalueChanged(int)), ui->horizontalSliderP, SLOT(setValue(int)));

    /* Parametr I */
    QObject::connect(ui->horizontalSliderI, SIGNAL(valueChanged(int)), simulation, SLOT(setParametrI(int)));
    QObject::connect(simulation, SIGNAL(IsliderChanged(double)), ui->doubleSpinBoxI, SLOT(setValue(double)));

    QObject::connect(ui->doubleSpinBoxI, SIGNAL(valueChanged(double)), simulation, SLOT(setParametrI(double)));
    QObject::connect(simulation, SIGNAL(IvalueChanged(int)), ui->horizontalSliderI, SLOT(setValue(int)));

    /* Parametr D */
    QObject::connect(ui->horizontalSliderD, SIGNAL(valueChanged(int)), simulation, SLOT(setParametrD(int)));
    QObject::connect(simulation, SIGNAL(DsliderChanged(double)), ui->doubleSpinBoxD, SLOT(setValue(double)));

    QObject::connect(ui->doubleSpinBoxD, SIGNAL(valueChanged(double)), simulation, SLOT(setParametrD(double)));
    QObject::connect(simulation, SIGNAL(DvalueChanged(int)), ui->horizontalSliderD, SLOT(setValue(int)));

    /* Wybór kulki */
    QObject::connect(ui->radioButtonMalaKulka, SIGNAL(toggled(bool)), simulation, SLOT(setMalaKulka()));
    QObject::connect(ui->radioButtonSredniaKulka, SIGNAL(toggled(bool)), simulation, SLOT(setSredniaKulka()));
    QObject::connect(ui->radioButtonDuzaKulka, SIGNAL(toggled(bool)), simulation, SLOT(setDuzaKulka()));
    QObject::connect(simulation, SIGNAL(kulkaChanged(int)), scene, SLOT(setKulka(int)));
    QObject::connect(simulation, SIGNAL(kulkaSelected(bool)), scene, SLOT(setKulkaVisible(bool)));

    /* Czas symulacji */
    QObject::connect(ui->spinBoxCzasSymulacji, SIGNAL(valueChanged(int)), simulation, SLOT(setCzas(int)));
    QObject::connect(simulation, SIGNAL(czasChanged(int)), ui->progressBar, SLOT(setMaximum(int)));

    /* Start / Stop symulacji */
    QObject::connect(ui->pushButtonStartStopSymulacji, SIGNAL(clicked(bool)), simulation, SLOT(changeStan()));
    QObject::connect(simulation, SIGNAL(stanChanged(int)), simulation, SLOT(setSimulation()));
    QObject::connect(simulation, SIGNAL(kulkaChanged(int)), simulation, SLOT(setSimulation()));
    QObject::connect(simulation, SIGNAL(wybierzKulke(bool)), ui->labelUwaga, SLOT(setVisible(bool)));

    /* Przebieg symulacji */
    QObject::connect(simulation, SIGNAL(startSimulation(int)), timer, SLOT(start()));
    QObject::connect(timer, SIGNAL(timeout()), simulation, SLOT(stepSimulation()));
    QObject::connect(simulation, SIGNAL(simulationChanged(int)), ui->progressBar, SLOT(setValue(int)));

    QObject::connect(simulation, SIGNAL(startSimulation(int)), ui->progressBar, SLOT(setValue(int)));
    QObject::connect(simulation, SIGNAL(stopSimulation(int)), ui->progressBar, SLOT(setValue(int)));

    QObject::connect(ui->doubleSpinBoxWartoscZadana, SIGNAL(valueChanged(double)), simulation, SLOT(setWartoscZadana(double)));

    /* Wizualizacja */
    QObject::connect(simulation, SIGNAL(pozycjaChanged(double)), scene, SLOT(setKulkaPosition(double)));
    QObject::connect(simulation, SIGNAL(pozycjaChanged(QString)), ui->lineEditPozycja, SLOT(setText(QString)));
    QObject::connect(simulation, SIGNAL(szybkoscChanged(QString)), ui->lineEditSzybkosc, SLOT(setText(QString)));
    QObject::connect(simulation, SIGNAL(sterowanieChanged(QString)), ui->lineEditSterowanie, SLOT(setText(QString)));
    QObject::connect(simulation, SIGNAL(pradChanged(QString)), ui->lineEditPrad, SLOT(setText(QString)));

    /* Inicjalizacja symulacji */
    simulation->initialize(ui->pushButtonStartStopSymulacji, timer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

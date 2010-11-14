#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "ui_about.h"
#include "addteam.h"
#include "ui_addteam.h"
#include "addmaster.h"
#include "ui_addteam.h"
#include "managemaster.h"
#include "ui_managemaster.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include <QMessageBox>
#include "master.h"
#include "equipe.h"
#include "parser/pokedexmanager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pokedexManager = new PokedexManager();
    masters = new QList<Master>();
    equipe = new QList<Equipe>();
    pokedexManager->initParser();
    pokemons = pokedexManager->getPokemonsList();

    QObject::connect(ui->actionFermer, SIGNAL(triggered()), qApp, SLOT(quit()));
    QObject::connect(ui->actionAproposQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    QObject::connect(ui->actionApropos, SIGNAL(triggered()), this, SLOT(afficherApropos()));
    QObject::connect(ui->actionDocumentation, SIGNAL(triggered()), this, SLOT(afficherDocumentation()));
    QObject::connect(ui->actionNouvelleEquipe, SIGNAL(triggered()), this, SLOT(afficherNouvelleEquipe()));
    QObject::connect(ui->actionGererEquipes, SIGNAL(triggered()), this, SLOT(afficherGererEquipes()));
    QObject::connect(ui->actionNouveauDresseur, SIGNAL(triggered()), this, SLOT(afficherNouveauDresseur()));
    QObject::connect(ui->actionGererDresseurs, SIGNAL(triggered()), this, SLOT(afficherGererDresseurs()));
    QObject::connect(ui->pokemonList, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(afficherPokemonDetails(QListWidgetItem *, QListWidgetItem *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::popMessage(const QString &title, const QString &text, const QIcon &icon)
{
    QMessageBox *message = new QMessageBox(QMessageBox::NoIcon, QString(title), QString(text));

    message->setWindowIcon(icon);
    message->exec();
}

QList<DPokemon> MainWindow::getPokemons() const
{
    return *pokemons;
}

void MainWindow::loadPokemons(const QList<DPokemon> &pokemons)
{
    for (int i = 0; i < pokemons.count(); i++)
    {
        QListWidgetItem *pokemon = new QListWidgetItem();
        QString *filename = new QString(":/Pokemons/ressources/");

        filename->append(pokemons.at(i).getId());
        filename->append(QString(".gif"));
        pokemon->setIcon(QIcon(*filename));
        pokemon->setText(pokemons.at(i).getName().toLower());
        ui->pokemonList->addItem(pokemon);
    }
}

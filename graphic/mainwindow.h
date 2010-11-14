#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "parser/pokedexmanager.h"
#include "master.h"
#include "equipe.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QList<DPokemon>     getPokemons() const;
    void                loadPokemons(const QList<DPokemon> &pokemons);
    void                popMessage(const QString &title, const QString &text, const QIcon &icon);

public slots:
    void    afficherPokemonDetails(QListWidgetItem *, QListWidgetItem *);
    void    afficherApropos();
    void    afficherDocumentation();
    void    afficherNouvelleEquipe();
    void    afficherGererEquipes();
    void    afficherNouveauDresseur();
    void    afficherGererDresseurs();

private:
    Ui::MainWindow  *ui;
    PokedexManager  *pokedexManager;
    QList<Master>   *masters;
    QList<Equipe>   *equipe;
    QList<DPokemon> *pokemons;
};

#endif // MAINWINDOW_H

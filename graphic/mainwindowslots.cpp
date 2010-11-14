#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "ui_about.h"
#include "addteam.h"
#include "ui_addteam.h"
#include "addmaster.h"
#include "ui_addteam.h"
#include "master.h"
#include "managemaster.h"
#include "ui_managemaster.h"
#include "manageteam.h"
#include "ui_manageteam.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QBuffer>
#include <QList>
#include <QListWidgetItem>
#include "parser/pokedexmanager.h"
#include <iostream>

void                MainWindow::afficherPokemonDetails(QListWidgetItem *current, QListWidgetItem *previous)
{
    DPokemon        p;
    QString         *filename = new QString(":/Pokemons/ressources/");
    int             idx;

    p.setName(current->text().toUpper());
    idx = this->pokemons->indexOf(p);
    p = pokemons->at(idx);
    filename->append(p.getId());
    filename->append(QString(".gif"));
    ui->pokemonName->setText(p.getName().toLower());
    ui->pokemonIcon->setPixmap(QPixmap(*filename));
    ui->pokemonId->setText(p.getId());
    ui->pokemonType->setText(p.getType());
    ui->pokemonAbility->setText(p.getAbility());
    ui->pokemonExp->setText(p.getExp());
    ui->pokemonRatio->setText(p.getRatio());
    ui->pokemonEggGroup->setText(p.getEggGroup());
    ui->pokemonSpecies->setText(p.getSpecies());
    ui->pokemonHeight->setText(p.getHeight());
    ui->pokemonWeight->setText(p.getWeight());
    ui->pokemonDescription->setText(p.getDescription());
    ui->moveList->clear();
    QList<Move> m(p.getMove());
    for (int i = 0; i < m.count(); i++)
    {
        QString item("");
        if (m[i].getLvl() != "")
        {
            item.append("Lv.");
            item.append(m[i].getLvl());
            item.append(" ");
        }
        item.append(m[i].getName());
        ui->moveList->addItem(item);
    }
    ui->evoList->clear();
    QList<Evo> e(p.getEvo());
    for (int i = 0; i < e.count(); i++)
    {
        QString pokemonDetails("");
        QString iconPath(":/Pokemons/ressources/");
        iconPath.append(e[i].getId());
        iconPath.append(".gif");
        if (e[i].getLvl() != "")
        {
            pokemonDetails.append("Lv.");
            pokemonDetails.append(e[i].getLvl());
            pokemonDetails.append(" ");
        }
        pokemonDetails.append(e[i].getName());
        ui->evoList->addItem(new QListWidgetItem(QIcon(iconPath), pokemonDetails));
    }
}

void                MainWindow::afficherApropos()
{
    (new About())->exec();
}

void                MainWindow::afficherDocumentation()
{
    QDesktopServices::openUrl(QUrl("http://code.google.com/p/pokedex2010/wiki/Documentation"));
}

void                MainWindow::afficherNouvelleEquipe()
{
    addteam         *a = new addteam(this);

    for (int i = 0; i < masters->count(); i++)
        a->setMaster(&masters->at(i));
    if (!masters->count())
        this->popMessage(QString("Nouvelle equipe"),
                        QString("Vous ne pouvez pas creer d'equipe sans dresseur."),
                        a->windowIcon());
    else
    {
        a->setMasterFocus();
        a->exec();
        QList<QListWidgetItem *> pokemons = a->getPokemonItems();
        if (pokemons.count() < 1 || pokemons.count() > 7)
            this->popMessage(QString("Nouvelle equipe"),
                            QString("Une equipe doit avoir entre 1 et 7 pokemons."),
                            a->windowIcon());
        else
        {
            QList<QListWidgetItem *> master = a->getMasterItem();
            QString *masterName = new QString(master[0]->text());
            QList<QString> *pokemonNames = new QList<QString>();
            for (int i = 0; i < pokemons.count(); i++)
                pokemonNames->append(pokemons[i]->text());
            Equipe *e = new Equipe(masterName, pokemonNames);
            this->equipe->append(*e);
            this->popMessage(QString("Nouvelle equipe"),
                            QString("L'equipe a ete cree avec succes (cf. Gerer les equipes)."),
                            a->windowIcon());
        }
    }
}

void                MainWindow::afficherGererEquipes()
{
    manageteam      *a = new manageteam(this);

    for (int i = 0; i < equipe->count(); i++)
        a->setEquipe(&equipe->at(i));
    if (!equipe->count())
        this->popMessage(QString("Gerer les equipes"),
                        QString("Vous ne pouvez pas gerer des equipes qui n'existent pas."),
                        a->windowIcon());
    else
        a->exec();
}

void                MainWindow::afficherNouveauDresseur()
{
    addmaster       *a = new addmaster(this);

    a->exec(); // if return QDialog::Accepted
    QIcon   masterIcon = a->getMasterIcon();
    QString masterName = a->getMasterName();
    Master *m = new Master(masterIcon, masterName);
    if (masters->indexOf(*m) == -1)
    {
        QAction *action = ui->menuDresseurs->addAction(masterIcon, masterName);
        m->setAction(action);
        masters->append(*m);
        this->popMessage(QString("Nouveau dresseur"),
                        QString("Le dresseur a ete cree avec succes (cf. Dresseurs)."),
                        a->windowIcon());
    }
    else
        this->popMessage(QString("Nouveau dresseur"),
                        QString("Un dresseur de ce nom existe déjà."),
                        a->windowIcon());
    delete m;
}

void                MainWindow::afficherGererDresseurs()
{
    managemaster    *a = new managemaster(this);
    for (int i = 0; i < masters->count(); i++)
        a->setMaster(&masters->at(i));
    if (!masters->count())
        this->popMessage(QString("Gerer les dresseurs"),
                        QString("Vous ne pouvez pas gerer des dresseurs qui n'existent pas."),
                        a->windowIcon());
    else
    {
        a->exec();
        QList<QListWidgetItem *> items = a->getSelectedItems();

        for (int i = 0; i < items.count(); i++)
        {
            int idx = 0;
            Master *m = new Master(items[i]->icon(), items[i]->text());
            if (!((idx = masters->indexOf(*m)) == -1))
            {
                ui->menuDresseurs->removeAction(masters->at(idx).getAction());
                masters->removeAt(idx);
            }
            this->popMessage(QString("Gerer les dresseurs"),
                            QString("La suppression a ete effectue avec succes (cf. Dresseurs)."),
                            a->windowIcon());
        }
    }
}

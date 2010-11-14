#include <QListWidgetItem>
#include "manageteam.h"
#include "ui_manageteam.h"
#include "master.h"
#include "equipe.h"

manageteam::manageteam(QWidget *parent) : QDialog(parent), ui(new Ui::manageteam)
{
    ui->setupUi(this);
}

manageteam::~manageteam()
{
    delete ui;
}

void                        manageteam::setEquipe(const Equipe *e)
{
    QString                 team;
    QList<QString>          pokemonList;

    pokemonList = e->getPokemonNames();
    team.append(e->getMasterName());
    team.append(" : ");
    for (int i = 0; i < pokemonList.count(); i++)
    {
        team.append(pokemonList[i]);
        if ((i + 1) == pokemonList.count())
            team.append(".");
        else
            team.append(", ");
    }
    ui->teamList->addItem(team);
}

QList<QListWidgetItem *>    manageteam::getSelectedItems() const
{
    return ui->teamList->selectedItems();
}

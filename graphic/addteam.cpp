#include <QList>
#include <QListWidgetItem>
#include "addteam.h"
#include "ui_addteam.h"

addteam::addteam(QWidget *parent) : QDialog(parent), ui(new Ui::addteam)
{
    ui->setupUi(this);
    QObject::connect(ui->teamCreate, SIGNAL(clicked()), this, SLOT(teamCreate()));
}

addteam::~addteam()
{
    delete ui;
}

void                        addteam::setMaster(const Master *m)
{
    ui->masterList->addItem(new QListWidgetItem(m->getIcon(), m->getName()));
}

void                        addteam::setMasterFocus()
{
    ui->masterList->setCurrentRow(0);
}

QList<QListWidgetItem *>    addteam::getMasterItem() const
{
    return ui->masterList->selectedItems();
}

QList<QListWidgetItem *>    addteam::getPokemonItems() const
{
    return ui->pokemonList->selectedItems();
}

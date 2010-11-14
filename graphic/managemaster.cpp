#include <QList>
#include <QListWidgetItem>
#include "managemaster.h"
#include "ui_managemaster.h"
#include "master.h"

managemaster::managemaster(QWidget *parent) : QDialog(parent), ui(new Ui::managemaster)
{
    ui->setupUi(this);
    QObject::connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(masterRemoved()));
}

managemaster::~managemaster()
{
    delete ui;
}

QList<QListWidgetItem *>    managemaster::getSelectedItems() const
{
    return ui->masterList->selectedItems();
}

void                        managemaster::setMaster(const Master *m)
{
    ui->masterList->addItem(new QListWidgetItem(m->getIcon(), m->getName()));
}

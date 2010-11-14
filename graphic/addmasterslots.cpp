#include "addmaster.h"
#include "ui_addmaster.h"

void    addmaster::updateMasterName(const QString &input)
{
    ui->masterName->setText(input);
}

void    addmaster::updateMasterIcon(QListWidgetItem *current, QListWidgetItem *next)
{
    ui->masterIcon->setPixmap(current->icon().pixmap(50,50));
}

void    addmaster::masterCreate()
{
    this->hide();
}

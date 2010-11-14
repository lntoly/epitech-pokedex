#include "addmaster.h"
#include "ui_addmaster.h"

addmaster::addmaster(QWidget *parent) : QDialog(parent), ui(new Ui::addmaster)
{
    ui->setupUi(this);
    ui->masterIcon->setPixmap(QPixmap(":/Avatars/ressources/sacha.png"));
    QObject::connect(ui->masterNameUser, SIGNAL(textChanged(const QString &)), this, SLOT(updateMasterName(const QString &)));
    QObject::connect(ui->masterIconUser, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(updateMasterIcon(QListWidgetItem *, QListWidgetItem *)));
    QObject::connect(ui->masterCreate, SIGNAL(clicked()), this, SLOT(masterCreate()));
}

addmaster::~addmaster()
{
    delete ui;
}

QString     addmaster::getMasterName() const
{
    return ui->masterName->text();
}

QIcon       addmaster::getMasterIcon() const
{
    return QIcon(*ui->masterIcon->pixmap());
}

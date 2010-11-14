#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);
    QObject::connect(ui->button, SIGNAL(clicked()), this, SLOT(fermerApropos()));
}

About::~About()
{
    delete ui;
}

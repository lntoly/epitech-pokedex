#ifndef ADDTEAM_H
#define ADDTEAM_H

#include <QDialog>
#include <QListWidget>
#include "master.h"

namespace Ui {
    class addteam;
}

class addteam : public QDialog
{
    Q_OBJECT

public:
    explicit addteam(QWidget *parent = 0);
    ~addteam();

    void                        setMaster(const Master *m);
    void                        setMasterFocus();
     QList<QListWidgetItem *>   getMasterItem() const;
     QList<QListWidgetItem *>   getPokemonItems()const;

public slots:
    void    teamCreate();

private:
    Ui::addteam     *ui;
};

#endif // ADDTEAM_H

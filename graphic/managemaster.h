#ifndef MANAGEMASTER_H
#define MANAGEMASTER_H

#include <QList>
#include <QDialog>
#include <QListWidgetItem>
#include "master.h"


namespace Ui {
    class managemaster;
}

class managemaster : public QDialog
{
    Q_OBJECT

public:
    explicit managemaster(QWidget *parent = 0);
    ~managemaster();

    QList<QListWidgetItem *>    getSelectedItems() const;
    void                        setMaster(const Master *m);

public slots:
    void    masterRemoved();

private:
    Ui::managemaster    *ui;
};

#endif // MANAGEMASTER_H

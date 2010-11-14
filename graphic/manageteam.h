#ifndef MANAGETEAM_H
#define MANAGETEAM_H

#include <QList>
#include <QDialog>
#include <QListWidgetItem>
#include "equipe.h"

namespace Ui {
    class manageteam;
}

class manageteam : public QDialog
{
    Q_OBJECT

public:
    explicit manageteam(QWidget *parent = 0);
    ~manageteam();

    QList<QListWidgetItem *>    getSelectedItems() const;
    void                        setEquipe(const Equipe *e);

private:
    Ui::manageteam *ui;
};

#endif // MANAGETEAM_H

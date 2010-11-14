#ifndef ADDMASTER_H
#define ADDMASTER_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
    class addmaster;
}

class addmaster : public QDialog
{
    Q_OBJECT

public:
    explicit addmaster(QWidget *parent = 0);
    ~addmaster();

    QString getMasterName() const;
    QIcon   getMasterIcon() const;

public slots:
    void    updateMasterName(const QString &);
    void    updateMasterIcon(QListWidgetItem *, QListWidgetItem *);
    void    masterCreate();

public:
    Ui::addmaster   *ui;
};

#endif // ADDMASTER_H

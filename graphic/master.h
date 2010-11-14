#ifndef MASTER_H
#define MASTER_H

#include <QIcon>
#include <QAction>

class Master
{
public:
    Master();
    Master(const Master &m);
    Master(QIcon masterIcon, QString masterName);
    ~Master();

    Master      &operator=(const Master &m);
    bool        operator==(const Master &m) const;
    void        setAction(QAction *action);
    QAction     *getAction() const;
    QIcon       getIcon() const;
    QString     getName() const;


private:
    QIcon       _icon;
    QString     _name;
    QAction     *_action;
};

#endif // MASTER_H

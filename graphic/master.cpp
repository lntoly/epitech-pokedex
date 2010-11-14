#include <QAction>
#include "master.h"

Master::Master()
{
    _icon = QIcon();
    _name = QString("");
}

Master::Master(QIcon masterIcon, QString masterName)
{
    _icon = masterIcon;
    _name = masterName;
}

Master::Master(const Master &m)
{
    _icon = m._icon;
    _name = m._name;
    _action = m._action;
}

Master::~Master()
{

}

Master      &Master::operator=(const Master &m)
{
    if (this != &m)
    {
        _icon = m._icon;
        _name = m._name;
        _action = m._action;
    }
    return *this;
}

void        Master::setAction(QAction *action)
{
    _action = action;
}

QIcon       Master::getIcon() const
{
    return _icon;
}

QString     Master::getName() const
{
    return _name;
}

QAction     *Master::getAction() const
{
    return _action;
}

bool        Master::operator==(const Master &m) const
{
    if (m._name.compare(_name) == 0)
        return true;
    return false;
}

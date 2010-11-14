#include "move.h"

Move::Move()
{
    _type = QString("");
    _name = QString("");
    _lvl = QString("");
}

Move::Move(const Move &p)
{
    this->_type = p._type;
    this->_name = p._name;
    this->_lvl = p._lvl;
}

Move::~Move()
{
}

Move&   Move::operator=(const Move &p)
{
    if (this != &p)
    {
        this->_type = p._type;
        this->_name = p._name;
        this->_lvl = p._lvl;
    }
    return *this;
}

void                Move::clear()
{
    this->setType(QString(""));
    this->setLvl(QString(""));
    this->setName(QString(""));
}

const QString       Move::getName() const
{
    return this->_name;
}

void                Move::setName(const QString name)
{
    this->_name = name;
}

const QString       Move::getType() const
{
    return this->_type;
}

void                Move::setType(const QString type)
{
    this->_type = type;
}

const QString       Move::getLvl() const
{
    return this->_lvl;
}
void                Move::setLvl(const QString lvl)
{
    this->_lvl = lvl;
}

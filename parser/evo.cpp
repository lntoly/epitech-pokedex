#include "evo.h"

Evo::Evo()
{
    _id = QString("");
    _name = QString("");
    _lvl = QString("");
}

Evo::Evo(const Evo &p)
{
    this->_id = p._id;
    this->_name = p._name;
    this->_lvl = p._lvl;
}

Evo::~Evo()
{
}

Evo&   Evo::operator=(const Evo &p)
{
    if (this != &p)
    {
        this->_id = p._id;
        this->_name = p._name;
        this->_lvl = p._lvl;
    }
    return *this;
}

void                Evo::clear()
{
    this->setId(QString(""));
    this->setLvl(QString(""));
    this->setName(QString(""));
}

const QString       Evo::getName() const
{
    return this->_name;
}

void                Evo::setName(const QString name)
{
    this->_name = name;
}

const QString       Evo::getId() const
{
    return this->_id;
}

void                Evo::setId(const QString id)
{
    this->_id = id;
}

const QString       Evo::getLvl() const
{
    return this->_lvl;
}
void                Evo::setLvl(const QString lvl)
{
    this->_lvl = lvl;
}


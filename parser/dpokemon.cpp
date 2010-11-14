#include "dpokemon.h"
#include "evo.h"
#include <iostream>

DPokemon::DPokemon()
{
    this->_ability = QString("");
    this->_description = QString("");
    this->_egg_group = QString("");
    this->_species = QString("");
    this->_exp = QString("");
    this->_height = QString("");
    this->_ratio = QString("");
    this->_weight = QString("");
    this->_type = QString("");
    this->_id = QString("");
    this->_name = QString("");
    this->_hp = QString("");
    this->_atk = QString("");
    this->_def = QString("");
    this->_spd = QString("");
    this->_sat = QString("");
    this->_sdf = QString("");
    this->_evo.clear();
    this->_moves.clear();
}

DPokemon::~DPokemon()
{
}

DPokemon::DPokemon(const DPokemon& p)
{
    this->_type = p._type;
    this->_ability = p._ability;
    this->_description = p._description;
    this->_egg_group = p._egg_group;
    this->_exp = p._exp;
    this->_height = p._height;
    this->_ratio = p._ratio;
    this->_species = p._species;
    this->_weight = p._weight;
    this->_id = p._id;
    this->_name = p._name;
    this->_hp = p._hp;
    this->_atk = p._atk;
    this->_def = p._def;
    this->_spd = p._spd;
    this->_sat = p._sat;
    this->_sdf = p._sdf;
    this->_evo = p._evo;
    this->_moves = p._moves;
}

DPokemon&           DPokemon::operator=(const DPokemon& p)
{
    if (this != &p)
    {
        _type = p._type;
        _ability = p._ability;
        _description = p._description;
        _egg_group = p._egg_group;
        _exp = p._exp;
        _height = p._height;
        _ratio = p._ratio;
        _species = p._species;
        _weight = p._weight;
        _id = p._id;
        _name = p._name;
        _hp = p._hp;
        _atk = p._atk;
        _def = p._def;
        _spd = p._spd;
        _sat = p._sat;
        _sdf = p._sdf;
        _evo = p._evo;
        _moves = p._moves;
    }
    return *this;
}

bool                DPokemon::operator==(const DPokemon& p)
{
    if (p.getName().compare(_name) == 0)
        return true;
    return false;
}

void                DPokemon::clear()
{
    this->setAbility(QString(""));
    this->setDescription(QString(""));
    this->_egg_group.clear();
    this->setSpecies(QString(""));
    this->setExp(QString(""));
    this->setHeight(QString(""));
    this->setRatio(QString(""));
    this->setWeight(QString(""));
    this->_type.clear();
    this->setId(QString(""));
    this->setName(QString(""));
    this->setHp(QString(""));
    this->setAtk(QString(""));
    this->setDef(QString(""));
    this->setSpd(QString(""));
    this->setSat(QString(""));
    this->setSdf(QString(""));
    this->_evo.clear();
    this->_moves.clear();
}

const QString       DPokemon::getName() const
{
     return this->_name;
}

void                DPokemon::setName(const QString name)
{
     this->_name = name;
}

const QString       DPokemon::getId() const
{
     return this->_id;
}

void                DPokemon::setId(const QString id)
{
    this->_id = id;
}

const QString       DPokemon::getType() const
{
    return this->_type;
}

void                DPokemon::setType(const QString s)
{
    if (this->_type.length() == 0)
        this->_type = s;
    else
    {
        this->_type.append(" / ");
        this->_type.append(s);
    }
}

const QString       DPokemon::getAbility() const
{
    return this->_ability;
}

void                DPokemon::setAbility(const QString s)
{
    this->_ability = s;
}

const QString       DPokemon::getExp() const
{
    return this->_exp;
}

void                DPokemon::setExp(const QString i)
{
    this->_exp = i;
}

const QString       DPokemon::getRatio() const
{
    return this->_ratio;
}

void                DPokemon::setRatio(const QString f)
{
    this->_ratio = f;
}

const QString       DPokemon::getEggGroup() const
{
    return this->_egg_group;
}

void                DPokemon::setEggGroup(const QString s)
{
    if (this->_egg_group.length() == 0)
        this->_egg_group = s;
    else
    {
        this->_egg_group.append(" / ");
        this->_egg_group.append(s);
    }
}

const QString       DPokemon::getSpecies() const
{
    return this->_species;
}

void                DPokemon::setSpecies(const QString s)
{
    this->_species = s;
}

const QString       DPokemon::getHeight() const
{
    return this->_height;
}

void                DPokemon::setHeight(const QString f)
{
    this->_height = f;
}

const QString       DPokemon::getWeight() const
{
    return this->_weight;
}

void                DPokemon::setWeight(const QString f)
{
    this->_weight = f;
}
		
const QString       DPokemon::getDescription() const
{
    return this->_description;
}

void                DPokemon::setDescription(const QString s)
{
    this->_description = s;
}

const QString       DPokemon::getHp() const
{
    return this->_hp;
}

void                DPokemon::setHp(const QString nb)
{
    this->_hp = nb;
}

const QString       DPokemon::getAtk() const
{
    return _atk;
}

void                DPokemon::setAtk(const QString nb)
{
    _atk = nb;
}

const QString       DPokemon::getDef() const
{
    return _def;
}

void                DPokemon::setDef(const QString nb)
{
    _def = nb;
}

const QString       DPokemon::getSpd() const
{
    return _spd;
}

void                DPokemon::setSpd(const QString nb)
{
    _spd = nb;
}

const QString       DPokemon::getSat() const
{
    return _sat;
}

void                DPokemon::setSat(const QString nb)
{
    _sat = nb;
}

const QString       DPokemon::getSdf() const
{
    return _sdf;
}

void                DPokemon::setSdf(const QString nb)
{
   _sdf = nb;
}

const QList<Evo>    DPokemon::getEvo() const
{
    return _evo;
}

void                DPokemon::setEvo(const QList<Evo> p)
{
    _evo = p;
}

const QList<Move>   DPokemon::getMove() const
{
    return _moves;
}

void                DPokemon::setMove(const QList<Move> p)
{
    _moves = p;
}

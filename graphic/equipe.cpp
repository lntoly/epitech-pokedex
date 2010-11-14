#include <QList>
#include <QString>
#include "equipe.h"

Equipe::Equipe()
{
    _masterName = new QString();
    _pokemonNames = new QList<QString>();
}

Equipe::Equipe(const Equipe &e)
{
    _masterName = new QString(*e._masterName);
    _pokemonNames = new QList<QString>(*e._pokemonNames);
}

Equipe::Equipe(QString *masterName, QList<QString> *pokemonNames)
{
    _masterName = masterName;
    _pokemonNames = pokemonNames;
}

Equipe::~Equipe()
{
    delete _masterName;
    delete _pokemonNames;
}

Equipe          &Equipe::operator=(const Equipe &e)
{
    if (this != &e)
    {
        _masterName = e._masterName;
        _pokemonNames = e._pokemonNames;
    }
    return *this;
}

QString         Equipe::getMasterName() const
{
    return *_masterName;
}

QList<QString>  Equipe::getPokemonNames() const
{
    return *_pokemonNames;
}

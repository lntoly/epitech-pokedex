#ifndef EQUIPE_H
#define EQUIPE_H

#include <QList>

class Equipe
{
public:
    Equipe();
    Equipe(const Equipe &e);
    Equipe(QString *masterName, QList<QString> *pokemonNames);
    ~Equipe();

    Equipe          &operator=(const Equipe &e);
    QString         getMasterName() const;
    QList<QString>  getPokemonNames() const;

private:
    QString         *_masterName;
    QList<QString>  *_pokemonNames;
};

#endif // EQUIPE_H

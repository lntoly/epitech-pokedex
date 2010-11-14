#ifndef __DPOKEMON_H__
# define __DPOKEMON_H__

#include <qstring>
#include <QList>
#include "evo.h"
#include "move.h"

class DPokemon
{
    public:
        DPokemon();
        ~DPokemon();
        DPokemon(const DPokemon&);
        DPokemon&               operator=(const DPokemon&);
        bool                    operator==(const DPokemon&);

        const QString           getType() const;
        void			setType(const QString);
        const QString           getAbility() const;
        void			setAbility(const QString);
        const QString		getExp() const;
        void			setExp(const QString);
        const QString		getRatio() const;
        void			setRatio(const QString);
        const QString           getEggGroup() const;
        void			setEggGroup(const QString);
        const QString           getSpecies() const;
        void			setSpecies(const QString);
        const QString		getHeight() const;
        void			setHeight(const QString);
        const QString		getWeight() const;
        void			setWeight(const QString);
        const QString           getDescription() const;
        void			setDescription(const QString);
        const QString		getName() const;
        void                    setName(const QString);
        const QString		getId() const;
        void                    setId(const QString);
        const QString           getHp() const;
        void                    setHp(const QString);
        const QString           getAtk() const;
        void                    setAtk(const QString);
        const QString           getDef() const;
        void                    setDef(const QString);
        const QString           getSpd() const;
        void                    setSpd(const QString);
        const QString           getSat() const;
        void                    setSat(const QString);
        const QString           getSdf() const;
        void                    setSdf(const QString);
        const QList<Evo>        getEvo() const;
        void                    setEvo(const QList<Evo>);
        const QList<Move>       getMove() const;
        void                    setMove(const QList<Move>);
        void                    clear();

private:
        QString 	_id;
        QString		_name;
        QString		_type;
        QString		_ability;
        QString		_exp;
        QString		_ratio;
        QString		_egg_group;
        QString		_species;
        QString		_height;
        QString		_weight;
        QString		_description;
        QString         _hp;
        QString         _atk;
        QString         _def;
        QString         _spd;
        QString         _sat;
        QString         _sdf;
        QList<Evo>      _evo;
        QList<Move>	_moves;
};

#endif

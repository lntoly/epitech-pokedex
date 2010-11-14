#ifndef __POKEDEXMANAGER_H__
# define __POKEDEXMANAGER_H__

#include <qobject.h>
#include <qlist.h>
#include "dpokemon.h"

class PokedexManager : public QObject
{
    Q_OBJECT

    public:
        PokedexManager();
        ~PokedexManager();
        void                initParser();
        QList<DPokemon>     *getPokemonsList() const;

    private:
        QList<DPokemon>     *_pokeList;
        DPokemon            *_currentPokemon;
		
};

#endif

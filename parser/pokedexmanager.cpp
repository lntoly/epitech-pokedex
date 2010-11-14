#include <QtXml/QXmlReader>
#include <QtXml/QXmlSimpleReader>
#include <QtXml/QXmlDefaultHandler>
#include <QtXml/QXmlInputSource>
#include <iostream>
#include <QFile>
#include "dpokemon.h"
#include "pokedexmanager.h"
#include "handler.h"

PokedexManager::PokedexManager() : QObject()
{
        this->_currentPokemon = new DPokemon;
        this->_pokeList = new QList<DPokemon>();
}

PokedexManager::~PokedexManager()
{
    delete this->_pokeList;
    delete this->_currentPokemon;
}

void			PokedexManager::initParser()
{
    QXmlSimpleReader xmlReader;
    QFile f("pokedata.xml"); // a foutre en macro
    if (!f.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "File : open failled." << std::endl;
        return;
    }
    QXmlInputSource src(&f);
    Handler *handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);
    bool ok = xmlReader.parse(src);
    f.close();
    if (!ok)
    {
        std::cerr << "Parsing failed." << std::endl;
        return;
    }
    _pokeList = handler->lPokemon();
}

QList<DPokemon>         *PokedexManager::getPokemonsList() const
{
    return _pokeList;
}

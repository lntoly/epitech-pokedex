#include <iostream>
#include <String>
#include <string.h>
#include "handler.h"
#include "dpokemon.h"

Handler::Handler() : QXmlDefaultHandler()
{
    indentationLevel = 0;
    balName = QString("");
    listPokemon.clear();
    _ismove = false;
}

bool    Handler::startElement(const QString &namespaceURI, const QString &localName,
                  const QString &qName, const QXmlAttributes &atts)
{
   balName = qName;
   indentationLevel += 1;
   if (indentationLevel == 2)
        tmp.setId(atts.value(0));
   else if (qName == "evolution")
       evotmp.setId(atts.value(0));
   else if (qName == "move")
       movetmp.setType(atts.value(0));
   else if (qName == "moves")
       this->setIsMove(true);
   return true;
}

bool    Handler::endElement(const QString &namespaceURI, const QString &localName,
                const QString &qName)
{
    indentationLevel -= 1;
    if (indentationLevel == 1)
    {
        addPokemon(tmp);
        tmp.clear();
        this->setIsMove(false);
    }
    else if (qName == "evolution")
    {
        addEvo(evotmp, tmp);
        evotmp.clear();
    }
    else if (qName == "move")
    {
        addMove(movetmp, tmp);
        movetmp.clear();
    }
    balName = QString("");
    return true;
}

bool    Handler::characters(const QString &str)
{
    if (balName == "name" && indentationLevel == 3)
        tmp.setName(str);
    else if (balName == "name" && this->getIsMove() == false)
        evotmp.setName(str);
    else if (balName == "name" && this->getIsMove() == true)
        movetmp.setName(str);
    else if (balName == "machine")
        movetmp.setType(str);
    else if (balName == "type")
        tmp.setType(str);
    else if (balName == "ability")
        tmp.setAbility(str);
    else if (balName == "exp")
        tmp.setExp(str);
    else if (balName == "male")
        tmp.setRatio(str);
    else if (balName == "weight")
        tmp.setWeight(str);
    else if (balName == "height")
        tmp.setHeight(str);
    else if (balName == "species")
        tmp.setSpecies(str);
    else if (balName == "description")
        tmp.setDescription(str);
    else if (balName == "egg-group")
        tmp.setEggGroup(str);
    else if (balName == "HP")
        tmp.setHp(str);
    else if (balName == "ATK")
        tmp.setAtk(str);
    else if (balName == "DEF")
        tmp.setDef(str);
    else if (balName == "SPD")
        tmp.setSpd(str);
    else if (balName == "SAT")
        tmp.setSat(str);
    else if (balName == "SDF")
        tmp.setSdf(str);
    else if (balName == "lvl" && this->getIsMove() == false)
        evotmp.setLvl(str);
    else if (balName == "lvl" && this->getIsMove() == true)
        movetmp.setLvl(str);
    return true;
}

void    Handler::addPokemon(const DPokemon &p)
{
    listPokemon.push_back(p);
}

void    Handler::addEvo(const Evo e, DPokemon &p)
{
    QList<Evo> tmp;
    tmp = p.getEvo();
    tmp.push_back(e);
    p.setEvo(tmp);
}

void    Handler::addMove(const Move e, DPokemon &p)
{
    QList<Move> tmp;
    tmp = p.getMove();
    tmp.push_back(e);
    p.setMove(tmp);
}

QList<DPokemon>*    Handler::lPokemon()
{
    return &listPokemon;
}

const bool          Handler::getIsMove()
{
    return _ismove;
}

void                Handler::setIsMove(const bool &b)
{
    _ismove = b;
}

bool    Handler::fatalError(const QXmlParseException &exception)
{
    std::cerr << "Parse error at line " << exception.lineNumber()
              << ", " << "column " << exception.columnNumber() << ": "
              << qPrintable(exception.message()) << std::endl;
    return false;
}

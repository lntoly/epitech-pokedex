#ifndef HANDLER_H
#define HANDLER_H

#include <QtXml/QXmlDefaultHandler>
#include "dpokemon.h"
#include "evo.h"
#include "move.h"

class Handler : public QXmlDefaultHandler
{
public:
    Handler();
    bool                startElement(const QString &namespaceURI, const QString &localName,
                                  const QString &qName, const QXmlAttributes &attributes);
    bool                endElement(const QString &namespaceURI, const QString &localName,
                                  const QString &qName);
    bool                characters(const QString &str);
    bool                fatalError(const QXmlParseException &exception);
    QList<DPokemon>*    lPokemon();
    void                addPokemon(const DPokemon &p);
    void                addEvo(const Evo, DPokemon&);
    void                addMove(const Move, DPokemon&);
    const bool          getIsMove();
    void                setIsMove(const bool&);

private :
    QList<DPokemon>     listPokemon;
    Evo                 evotmp;
    Move                movetmp;
    DPokemon            tmp;
    int                 indentationLevel;
    QString             balName;
    bool                _ismove;
};

#endif // HANDLER_H

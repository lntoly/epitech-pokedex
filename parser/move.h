#ifndef MOVE_H
#define MOVE_H

#include <QString>

class Move
{
public:
    Move();
    Move(const Move&);
    ~Move();
    Move& operator=(const Move&);

    const QString	getName() const;
    void                setName(const QString);
    const QString       getType() const;
    void                setType(const QString);
    const QString       getLvl() const;
    void                setLvl(const QString);
    void                clear();

private:
    QString _type;
    QString _name;
    QString _lvl;
};

#endif // MOVE_H

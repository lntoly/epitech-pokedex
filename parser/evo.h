#ifndef EVO_H
#define EVO_H

#include <QString>

class Evo
{
public:
    Evo();
    Evo(const Evo&);
    ~Evo();
    Evo& operator=(const Evo&);

    const QString	getName() const;
    void                setName(const QString);
    const QString       getId() const;
    void                setId(const QString);
    const QString       getLvl() const;
    void                setLvl(const QString);
    void                clear();

private:
    QString _id;
    QString _name;
    QString _lvl;
};

#endif // EVO_H

#ifndef SAIYAJIN_H
#define SAIYAJIN_H

#include "Character.h"

class Character;

class Saiyajin: public Character{
private:
    unsigned int level;
protected:
    Saiyajin(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork);
public:
    unsigned int getLevel() const;
    void takeDamage(unsigned int dmg);
};

#endif

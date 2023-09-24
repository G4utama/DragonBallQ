#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Character;

class Enemy: public Character{
private:
    unsigned int transformation;
protected:
    Enemy(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork);
public:
    unsigned int getTransformation() const;
    void takeDamage(unsigned int dmg);
};

#endif
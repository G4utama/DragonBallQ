#ifndef FREEZER_H
#define FREEZER_H

class Visitor;
#include "Enemy.h"
#include "Visitor.h"

class Freezer: public Enemy{
public:
    Freezer* clone() const;
    Freezer(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const override;
};

#endif
#ifndef MAJINBUU_H
#define MAJINBUU_H

class Visitor;
#include "Enemy.h"
#include "Visitor.h"

class MajinBuu: public Enemy{
public:
    MajinBuu* clone() const;
    MajinBuu(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const override;
};

#endif
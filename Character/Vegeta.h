#ifndef VEGETA_H
#define VEGETA_H

class Visitor;
#include "Saiyajin.h"
#include "Visitor.h"

class Vegeta: public Saiyajin{
public:
    Vegeta* clone() const;
    Vegeta(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const;
};

#endif
#ifndef GOKU_H
#define GOKU_H

class Visitor;
#include "Saiyajin.h"
#include "Visitor.h"

class Goku: public Saiyajin{
public:
    Goku* clone() const;
    Goku(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const override;
};

#endif
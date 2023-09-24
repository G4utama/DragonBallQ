#ifndef GOHAN_H
#define GOHAN_H

class Visitor;
#include "Saiyajin.h"
#include "Visitor.h"

class Gohan: public Saiyajin{
public:
    Gohan* clone() const;
    Gohan(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const override;
};

#endif
#ifndef TRUNKS_H
#define TRUNKS_H

class Visitor;
#include "Saiyajin.h"
#include "Visitor.h"

class Trunks: public Saiyajin{
public:
    Trunks* clone() const;
    Trunks(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const override;
};

#endif
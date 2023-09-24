#include "Vegeta.h"
#include "Visitor.h"

Vegeta* Vegeta::clone() const{
    return new Vegeta(*this);
}

Vegeta::Vegeta(const std::string& name, unsigned int maxHp,  unsigned int att, unsigned int level, const std::string& artwork): Saiyajin(name, maxHp, att, level, artwork) {}

//Big Bang Attack
void Vegeta::attack(CharacterSet& targetSet){
    unsigned int dmg = (getAtt() * getLevel()) * 1.5;
    doDamage(targetSet, targetSet.search(0), dmg);
}

void Vegeta::accept(Visitor& visitor) const{
    visitor.visit(*this);
}

#include "Gohan.h"
#include "Visitor.h"

Gohan* Gohan::clone() const{
    return new Gohan(*this);
}

Gohan::Gohan(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork): Saiyajin(name, maxHp, att, level, artwork) {}

//Masenko
void Gohan::attack(CharacterSet& targetSet){
    unsigned int dmg = getAtt() * getLevel();
    doDamage(targetSet, targetSet.search(0), dmg);
}

void Gohan::accept(Visitor& visitor) const{
    visitor.visit(*this);
}
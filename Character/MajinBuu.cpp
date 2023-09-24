#include "MajinBuu.h"
#include "Visitor.h"

MajinBuu* MajinBuu::clone() const{
    return new MajinBuu(*this);
}

MajinBuu::MajinBuu(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork): Enemy(name, maxHp, att, transformation, artwork) {}

//Kamehameha Majin
void MajinBuu::attack(CharacterSet& targetSet){
    unsigned int dmg = getAtt();
    doDamage(targetSet, targetSet.search(0), dmg);
}

void MajinBuu::accept(Visitor& visitor) const{
    visitor.visit(*this);
}

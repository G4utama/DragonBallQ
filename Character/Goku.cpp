#include "Goku.h"
#include "Visitor.h"

Goku* Goku::clone() const{
    return new Goku(*this);
}

Goku::Goku(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork): Saiyajin(name, maxHp, att, level, artwork) {}

//Kamehameha
void Goku::attack(CharacterSet& targetSet){
    unsigned int dmg;
    unsigned int x = 5;
    for(CharacterSet::Iterator it=targetSet.begin(); it!=targetSet.end() && (*it)->isAlive(); ++it){
        dmg = (getAtt()/2) + x;
        doDamage(targetSet, *it, dmg);
        x += 5;
    }
}

void Goku::accept(Visitor& visitor) const{
    visitor.visit(*this);
}

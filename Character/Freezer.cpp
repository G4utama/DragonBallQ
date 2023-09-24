#include "Freezer.h"
#include "Visitor.h"

Freezer* Freezer::clone() const{
    return new Freezer(*this);
}

Freezer::Freezer(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork): Enemy(name, maxHp, att, transformation, artwork) {}

//Raggio Letale
void Freezer::attack(CharacterSet& targetSet){
    unsigned int dmg;
    unsigned int x = 5;
    for(CharacterSet::Iterator it=targetSet.begin(); it!=targetSet.end() && (*it)->isAlive(); ++it){
        dmg = (getAtt()/2) + x;
        doDamage(targetSet, *it, dmg);
        x += 5;
    }
}

void Freezer::accept(Visitor& visitor) const{
    visitor.visit(*this);
}

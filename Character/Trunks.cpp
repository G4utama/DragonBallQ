#include "Trunks.h"
#include "Visitor.h"

Trunks* Trunks::clone() const{
    return new Trunks(*this);
}

Trunks::Trunks(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork): Saiyajin(name, maxHp, att, level, artwork) {}

//Spada Z
void Trunks::attack(CharacterSet& targetSet){
    unsigned int dmg;
    Character* temp;
    for(CharacterSet::Iterator it=targetSet.begin(); it!=targetSet.end() && (*it)->isAlive(); ++it){
        temp = *it;
        dmg = (getAtt() * getLevel())/2;
        doDamage(targetSet, *it, dmg);
        if(!(temp->isAlive()))
            return;
    }
}

void Trunks::accept(Visitor& visitor) const{
    visitor.visit(*this);
}

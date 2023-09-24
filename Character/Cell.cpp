#include "Cell.h"
#include "Visitor.h"

Cell* Cell::clone() const{
    return new Cell(*this);
}

Cell::Cell(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork): Enemy(name, maxHp, att, transformation, artwork) {}

//Big Bang Crash
void Cell::attack(CharacterSet& targetSet){
    unsigned int dmg;
    for(CharacterSet::Iterator it=targetSet.begin(); it!=targetSet.end() && (*it)->isAlive(); ++it){
        dmg = getAtt() / 2;
        doDamage(targetSet, *it, dmg);
    }
}

void Cell::accept(Visitor& visitor) const{
    visitor.visit(*this);
}

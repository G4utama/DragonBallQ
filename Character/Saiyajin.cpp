#include "Saiyajin.h"

Saiyajin::Saiyajin(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int level, const std::string& artwork):
           Character(name, maxHp, att, artwork), level(level) {}

void Saiyajin::takeDamage(unsigned int dmg){
    if(alive){
        if(hp > dmg){
            hp -= dmg;
        }else{
            hp = 0;
            alive = false;
        }
        for(auto it=observer.begin(); it!=observer.end(); ++it){
            (*it)->notify(*this);
        }
    }
}

unsigned int Saiyajin::getLevel() const{
    return level;
}

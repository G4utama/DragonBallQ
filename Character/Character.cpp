#include "Character.h"
#include <string>

Character::Character(const std::string& cName, unsigned int cMaxHp, unsigned int cAtt, const std::string& cArtwork): name(cName), maxHp(cMaxHp), att(cAtt), artwork(cArtwork), hp(cMaxHp), alive(true) {}

const std::string& Character::getName() const{
    return name;
}

unsigned int Character::getMaxHp() const{
    return maxHp;
}

unsigned int Character::getHp() const{
    return hp;
}

unsigned int Character::getAtt() const{
    return att;
}

const std::string& Character::getArtwork() const{
    return artwork;
}

bool Character::isAlive() const{
    return alive;
}

void Character::doDamage(CharacterSet& targetSet, Character*& target, unsigned int dmg) const{
    if(target->isAlive()){
        target->takeDamage(dmg);
        if(!(target->isAlive())){
            targetSet.moveBack(target);
            targetSet.setAliveCount(targetSet.getAlive()-1);
        }
    }
}

void Character::registerObserver(CharacterObserver* obs){
    observer.push_back(obs);
}

void Character::removeObserver(CharacterObserver* obs){
    for(auto it=observer.begin(); it!=observer.end(); ++it){
        if(obs == *it){
            observer.erase(it);
            return;
        }
    }
}

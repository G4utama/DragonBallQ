#include "Enemy.h"

Enemy::Enemy(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork): Character(name, maxHp, att, artwork), transformation(transformation) {}

unsigned int Enemy::getTransformation() const{
    return transformation;
}

void Enemy::takeDamage(unsigned int dmg){
    if(alive){
        if(hp > dmg/transformation){
            hp = hp-(dmg/transformation);
        }else{
            hp = 0;
            alive = false;
        }
        for(auto it=observer.begin(); it!=observer.end(); ++it){
            (*it)->notify(*this);
        }
    }
}

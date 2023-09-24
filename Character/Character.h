#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

#include "CharacterObserver.h"
#include "CharacterSet.h"
#include "Visitor.h"

class CharacterSet;
class Visitor;
class CharacterObserver;

class Character{
private:
    std::string name;
    unsigned int maxHp;
    unsigned int att;
    std::string artwork;
protected:
    unsigned int hp;
    bool alive;
    std::vector<CharacterObserver*> observer;
    Character(const std::string& cName, unsigned int cMaxHp, unsigned int cAtt, const std::string& cArtwork);
public:
    virtual ~Character()=default;
    virtual Character* clone() const=0;
    //get
    bool isAlive() const;
    const std::string& getName() const;
    unsigned int getMaxHp() const;
    unsigned int getHp() const;
    unsigned int getAtt() const;
    const std::string& getArtwork() const;
    //damage
    void doDamage(CharacterSet& targetSet, Character*& target, unsigned int dmg) const;
    virtual void takeDamage(unsigned int dmg)=0;
    virtual void attack(CharacterSet& targetSet)=0;
    //visitor, observer
    virtual void accept(Visitor& visitor) const=0;
    void registerObserver(CharacterObserver* obs);
    void removeObserver(CharacterObserver* obs);
};

#endif

#ifndef CHARACTER_SET_H
#define CHARACTER_SET_H

#include "Character.h"
#include "CharacterSetObserver.h"
#include <vector>

class Character;

class CharacterSet{
private:
    unsigned int maxDim;
    unsigned int dim;
    unsigned int stillAlive;
    Character** ptrS;
    std::vector<CharacterSetObserver*> observer;
    void moveCharacter(unsigned int first, unsigned int last); //sposta i puntatori dei character
public:
    class Iterator{
    friend class CharacterSet;
    private:
        Character** ptrI;
        Iterator(Character** ptr);
    public:
        Iterator();
        //operator
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        Character*& operator*() const;
        Character** operator->() const;
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
    };
    Iterator begin() const;
    Iterator end() const;

    explicit CharacterSet(unsigned int capacity = 0);
    ~CharacterSet();
    CharacterSet(const CharacterSet& s);

    void insertBack(Character* pc);
    void removeBack();
    Character*& search(unsigned int x) const;
    void moveAlive();
    void moveBack(Character*& x);
    //operator
    Character*& operator[](unsigned int i) const;
    CharacterSet& operator=(const CharacterSet& s);
    //get
    unsigned int getMaxDim() const;
    unsigned int getDim() const;
    unsigned int getAlive() const;
    void setAliveCount(unsigned int x);
    //observer
    void registerObserver(CharacterSetObserver* obs);
};

#endif

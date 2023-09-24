#ifndef CHARACTER_SET_OBSERVER_H
#define CHARACTER_SET_OBSERVER_H

#include "CharacterSet.h"

class CharacterSet;

class CharacterSetObserver{
public:
    virtual ~CharacterSetObserver() = default;
    virtual void notify(CharacterSet& set) = 0;
};

#endif

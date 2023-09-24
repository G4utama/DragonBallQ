#include "CharacterSet.h"
#include "CharacterSetObserver.h"
#include <stdexcept>

CharacterSet::Iterator::Iterator(Character** ptr): ptrI(ptr){}

CharacterSet::Iterator::Iterator(): ptrI(nullptr){}

//operator
CharacterSet::Iterator& CharacterSet::Iterator::operator++(){
    if(ptrI != nullptr)
        ptrI = ptrI+1;
    return *this;
}

CharacterSet::Iterator CharacterSet::Iterator::operator++(int){
    Iterator temp = *this;
    if(ptrI != nullptr)
        ptrI = ptrI+1;
    return temp;
}

CharacterSet::Iterator& CharacterSet::Iterator::operator--(){
    if(ptrI != nullptr)
        ptrI = ptrI-1;
    return *this;
}

CharacterSet::Iterator CharacterSet::Iterator::operator--(int){
    Iterator temp = *this;
    if(ptrI != nullptr)
        ptrI = ptrI-1;
    return temp;
}

Character*& CharacterSet::Iterator::operator*() const{
    return *ptrI;
}

Character** CharacterSet::Iterator::operator->() const{
    return ptrI;
}

bool CharacterSet::Iterator::operator==(const Iterator& it) const{
    return ptrI == it.ptrI;
}

bool CharacterSet::Iterator::operator!=(const Iterator& it) const{
    return ptrI != it.ptrI;
}



CharacterSet::Iterator CharacterSet::begin() const{
    return dim>0 ? Iterator(&ptrS[0]) : Iterator();
}

CharacterSet::Iterator CharacterSet::end() const{
    return dim>0 ? Iterator(&ptrS[dim]) : Iterator();
}

CharacterSet::CharacterSet(unsigned int maxDim): maxDim(maxDim), dim(0), stillAlive(maxDim), ptrS(maxDim>0 ? new Character*[maxDim] : nullptr){
    for(unsigned int i=0; i<maxDim; ++i){
        ptrS[i] = nullptr;
    }
}

CharacterSet::~CharacterSet(){
    if(ptrS != nullptr) {
        for(unsigned int i=0; i<maxDim; ++i)
            if(ptrS[i] != nullptr)
                delete ptrS[i];
        delete[] ptrS;
    }
}

CharacterSet::CharacterSet(const CharacterSet& s): maxDim(s.maxDim), dim(s.dim), stillAlive(s.stillAlive), ptrS(s.maxDim>0 && s.ptrS!=nullptr ? new Character*[s.maxDim] : nullptr){
    if(s.ptrS != nullptr) {
        for(unsigned int i=0; i<s.maxDim; ++i){
            if(s.ptrS[i] == nullptr){
                ptrS[i] = nullptr;
            }else{
                ptrS[i] = s.ptrS[i]->clone();
            }
        }
    }
}

Character*& CharacterSet::operator[](unsigned int i) const{
    return ptrS[i];
}

CharacterSet& CharacterSet::operator=(const CharacterSet& s){
    if(this != &s){
        if(ptrS != nullptr){
            for(unsigned int i=0; i<maxDim; ++i){
                if(ptrS[i] != nullptr){
                    delete ptrS[i];
                }
            }
            delete[] ptrS;
        }
        maxDim = s.maxDim;
        dim = s.dim;
        stillAlive = s.stillAlive;
        ptrS = s.maxDim>0 && s.ptrS!=nullptr ? new Character*[s.maxDim] : nullptr;
        if(s.ptrS != nullptr){
            for(unsigned int i=0; i<s.maxDim; ++i){
                if(s.ptrS[i] == nullptr){
                    ptrS[i] = nullptr;
                }else{
                    ptrS[i] = (s.ptrS[i])->clone();
                }
            }
        }
    }
    return *this;
}

void CharacterSet::insertBack(Character* c){
    if(dim<maxDim) {
        ptrS[dim] = c;
        ++dim;
    }
}

void CharacterSet::removeBack(){
    if(dim>0){
        --dim;
        delete ptrS[dim];
    }
}

Character*& CharacterSet::search(unsigned int x) const{
    return x < dim ? (*this).operator[](x) : (*this).operator[](dim-1);
}

void CharacterSet::moveCharacter(unsigned int first, unsigned int last){
    if(first==last){
        return;
    }else{
        Character* temp = ptrS[first];
        for(unsigned int i=first; i<last; ++i){
            ptrS[i] = ptrS[i+1];
        }
        ptrS[last] = temp;
    }
    for(auto it=observer.begin(); it!=observer.end(); ++it){
        (*it)->notify(*this);
    }
}

void CharacterSet::moveAlive(){
    moveCharacter(0, stillAlive-1);
}

void CharacterSet::moveBack(Character*& x){
    Character* temp = ptrS[stillAlive-1];
    ptrS[stillAlive-1] = x;
    x = temp;
    for(auto i=observer.begin(); i!=observer.end(); ++i){
        (*i)->notify(*this);
    }
}

//get
unsigned int CharacterSet::getMaxDim() const{
    return maxDim;
}

unsigned int CharacterSet::getDim() const{
    return dim;
}

unsigned int CharacterSet::getAlive() const{
    return stillAlive;
}

void CharacterSet::setAliveCount(unsigned int x){
    if(x<=dim){
        stillAlive = x;
    }
}

void CharacterSet::registerObserver(CharacterSetObserver* obs){
    observer.push_back(obs);
}

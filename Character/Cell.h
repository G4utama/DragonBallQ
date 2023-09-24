#ifndef CELL_H
#define CELL_H

class Visitor;
#include "Enemy.h"
#include "Visitor.h"

class Cell: public Enemy{
public:
    Cell* clone() const;
    Cell(const std::string& name, unsigned int maxHp, unsigned int att, unsigned int transformation, const std::string& artwork);

    void attack(CharacterSet& targetSet) override;
    void accept(Visitor& visitor) const override;
};

#endif
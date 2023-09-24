#ifndef VISITOR_H
#define VISITOR_H

class Goku;
class Vegeta;
class Trunks;
class Gohan;
class Freezer;
class Cell;
class MajinBuu;

class Visitor{
public:
    virtual ~Visitor()=default;
    virtual void visit(const Goku&)=0;
    virtual void visit(const Vegeta&)=0;
    virtual void visit(const Trunks&)=0;
    virtual void visit(const Gohan&)=0;
    virtual void visit(const Freezer&)=0;
    virtual void visit(const Cell&)=0;
    virtual void visit(const MajinBuu&)=0;
};

#endif
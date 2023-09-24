#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H

#include "Info.h"
//Character
#include "../Character/Visitor.h"
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
#include "../Character/MajinBuu.h"

class InfoVisitor: public Visitor{
private:
    Info* widget;
public:
    InfoVisitor(Info* widget);
    void visit(const Goku&);
    void visit(const Vegeta&);
    void visit(const Trunks&);
    void visit(const Gohan&);
    void visit(const Freezer&);
    void visit(const Cell&);
    void visit(const MajinBuu&);
};

#endif
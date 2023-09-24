#ifndef CHARACTER_WIDGET_VISITOR_H
#define CHARACTER_WIDGET_VISITOR_H

#include "CharacterWidget.h"
//Character
#include "../Character/Visitor.h"
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
#include "../Character/MajinBuu.h"

class CharacterWidgetVisitor: public Visitor{
private:
    CharacterWidget* widget;
public:
    CharacterWidgetVisitor(CharacterWidget* widget);
    void visit(const Goku&);
    void visit(const Vegeta&);
    void visit(const Trunks&);
    void visit(const Gohan&);
    void visit(const Freezer&);
    void visit(const Cell&);
    void visit(const MajinBuu&);
};

#endif

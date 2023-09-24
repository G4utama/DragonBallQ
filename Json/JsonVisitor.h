#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H

//Character
#include "../Character/Visitor.h"
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
#include "../Character/MajinBuu.h"
//QT
#include <QJsonObject>

class JsonVisitor: public Visitor{
private:
    QJsonObject content;
public:
    QJsonObject getContent() const;
    void visit(const Goku&);
    void visit(const Vegeta&);
    void visit(const Trunks&);
    void visit(const Gohan&);
    void visit(const Freezer&);
    void visit(const Cell&);
    void visit(const MajinBuu&);
};

#endif

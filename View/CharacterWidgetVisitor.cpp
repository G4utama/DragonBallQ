#include "CharacterWidgetVisitor.h"
//Character
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
#include "../Character/MajinBuu.h"

CharacterWidgetVisitor::CharacterWidgetVisitor(CharacterWidget* w): widget(w) {}

void CharacterWidgetVisitor::visit(const Goku& goku){
    widget->getTypeWidget()->setCurrentText("Goku");
    widget->getLevelWidget()->setValue(goku.getLevel());
}

void CharacterWidgetVisitor::visit(const Vegeta& vegeta){
    widget->getTypeWidget()->setCurrentText("Vegeta");
    widget->getLevelWidget()->setValue(vegeta.getLevel());
}

void CharacterWidgetVisitor::visit(const Trunks& trunks){
    widget->getTypeWidget()->setCurrentText("Trunks");
    widget->getLevelWidget()->setValue(trunks.getLevel());
}

void CharacterWidgetVisitor::visit(const Gohan& gohan){
    widget->getTypeWidget()->setCurrentText("Gohan");
    widget->getLevelWidget()->setValue(gohan.getLevel());
}

void CharacterWidgetVisitor::visit(const Freezer& freezer){
    widget->getTypeWidget()->setCurrentText("Freezer");
    widget->getLevelWidget()->setValue(freezer.getTransformation());
}

void CharacterWidgetVisitor::visit(const Cell& cell){
    widget->getTypeWidget()->setCurrentText("Cell");
    widget->getLevelWidget()->setValue(cell.getTransformation());
}

void CharacterWidgetVisitor::visit(const MajinBuu& majinbuu){
    widget->getTypeWidget()->setCurrentText("MajinBuu");
    widget->getLevelWidget()->setValue(majinbuu.getTransformation());
}
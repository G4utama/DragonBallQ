#include "InfoVisitor.h"
//Character
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
//QT
#include <QLabel>

InfoVisitor::InfoVisitor(Info* w): widget(w){}

void InfoVisitor::visit(const Goku& goku){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(goku.getName()));
    QLabel* level = widget->getLevelWidget();
    level->setText("Livello: "+QString::number(goku.getLevel()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Kamehameha:\nperfora i nemici e fa sempre più danno");
}

void InfoVisitor::visit(const Vegeta& vegeta){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(vegeta.getName()));
    QLabel* level = widget->getLevelWidget();
    level->setText("Livello: "+QString::number(vegeta.getLevel()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Big Bang Attack:\npotente attacco che infligge più danno al primo nemico");
}

void InfoVisitor::visit(const Trunks& trunks){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(trunks.getName()));
    QLabel* level = widget->getLevelWidget();
    level->setText("Livello: "+QString::number(trunks.getLevel()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Spada Z:\nscatta e taglia con la spada tutta la squadra nemica");
}

void InfoVisitor::visit(const Gohan& gohan){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(gohan.getName()));
    QLabel* level = widget->getLevelWidget();
    level->setText("Livello: "+QString::number(gohan.getLevel()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Masenko:\nsemplice attacco al primo nemico");
}

void InfoVisitor::visit(const Freezer& freezer){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(freezer.getName()));
    QLabel* armor = widget->getLevelWidget();
    armor->setText("Armatura: "+QString::number(freezer.getTransformation()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Raggio Letale:\nperfora i nemici e fa sempre più danno");
}

void InfoVisitor::visit(const Cell& cell){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(cell.getName()));
    QLabel* armor = widget->getLevelWidget();
    armor->setText("Armatura: "+QString::number(cell.getTransformation()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Big Bang Crash:\npotente attacco che danneggia tutta la squadra nemica");
}

void InfoVisitor::visit(const MajinBuu& majinbuu){
    QLabel* name = widget->getNameWidget();
    name->setText(QString::fromStdString(majinbuu.getName()));
    QLabel* armor = widget->getLevelWidget();
    armor->setText("Armatura: "+QString::number(majinbuu.getTransformation()));
    QLabel* action = widget->getAttackWidget();
    action->setText("Kamehameha Majin:\nKamehameha in versione MajinBuu");
}

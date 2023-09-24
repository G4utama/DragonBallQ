#include "JsonVisitor.h"
#include <QJsonObject>

QJsonObject JsonVisitor::getContent() const{
    return content;
}

void JsonVisitor::visit(const Goku& goku){
    QJsonObject objGoku;
    objGoku.insert("type", QJsonValue::fromVariant("goku"));
    objGoku.insert("level", QJsonValue::fromVariant(goku.getLevel()));
    content = objGoku;
}

void JsonVisitor::visit(const Vegeta& vegeta){
    QJsonObject objVegeta;
    objVegeta.insert("type", QJsonValue::fromVariant("vegeta"));
    objVegeta.insert("level", QJsonValue::fromVariant(vegeta.getLevel()));
    content = objVegeta;
}

void JsonVisitor::visit(const Trunks& trunks){
    QJsonObject objTrunks;
    objTrunks.insert("type", QJsonValue::fromVariant("trunks"));
    objTrunks.insert("level", QJsonValue::fromVariant(trunks.getLevel()));
    content = objTrunks;
}

void JsonVisitor::visit(const Gohan& gohan){
    QJsonObject objGohan;
    objGohan.insert("type", QJsonValue::fromVariant("gohan"));
    objGohan.insert("level", QJsonValue::fromVariant(gohan.getLevel()));
    content = objGohan;
}

void JsonVisitor::visit(const Freezer& freezer){
    QJsonObject objFreezer;
    objFreezer.insert("type", QJsonValue::fromVariant("freezer"));
    objFreezer.insert("level", QJsonValue::fromVariant(freezer.getTransformation()));
    content = objFreezer;
}

void JsonVisitor::visit(const Cell& cell){
    QJsonObject objCell;
    objCell.insert("type", QJsonValue::fromVariant("cell"));
    objCell.insert("level", QJsonValue::fromVariant(cell.getTransformation()));
    content = objCell;
}

void JsonVisitor::visit(const MajinBuu& majinbuu){
    QJsonObject objMajinBuu;
    objMajinBuu.insert("type", QJsonValue::fromVariant("majinbuu"));
    objMajinBuu.insert("level", QJsonValue::fromVariant(majinbuu.getTransformation()));
    content = objMajinBuu;
}

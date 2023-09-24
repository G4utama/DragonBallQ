#include "Info.h"
#include "InfoVisitor.h"

#include <QVBoxLayout>

Info::Info(Character* c, QWidget* p): QWidget(p), character(c){
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name = new QLabel();
    layout->addWidget(name);
    hp = new QLabel();
    layout->addWidget(hp);
    att = new QLabel();
    layout->addWidget(att);
    level = new QLabel();
    layout->addWidget(level);
    attack = new QLabel();
    layout->addWidget(attack);

    character->registerObserver(this);
}

QLabel* Info::getNameWidget() const{
    return name;
}

QLabel* Info::getHpWidget() const{
    return hp;
}

QLabel* Info::getAttWidget() const{
    return att;
}

QLabel* Info::getLevelWidget() const{
    return level;
}

QLabel* Info::getAttackWidget() const{
    return attack;
}

void Info::show(){
    hp->setText("HP: " + QString::number(character->getHp()) + "/" + QString::number(character->getMaxHp()));
    att->setText("ATT: " + QString::number(character->getAtt()));
    InfoVisitor visitor(this);
    character->accept(visitor);
}

void Info::notify(Character& c){
    hp->setText("HP: " + QString::number(c.getHp()) + "/" + QString::number(c.getMaxHp()));
}

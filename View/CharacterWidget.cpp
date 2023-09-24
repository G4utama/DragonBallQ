#include "CharacterWidget.h"
//Qt
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QFrame>
#include <QPushButton>

CharacterWidget::CharacterWidget(QWidget* parent): QFrame(parent){
    QHBoxLayout* hbox=new QHBoxLayout(this);

    QVBoxLayout* vbox=new QVBoxLayout();
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QFormLayout* form=new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);
    hbox->addLayout(vbox);

    //type
    type = new QComboBox();
    type->setObjectName("type");
    type->addItem("Goku");
    type->addItem("Vegeta");
    type->addItem("Trunks");
    type->addItem("Gohan");
    type->addItem("Freezer");
    type->addItem("Cell");
    type->addItem("MajinBuu");
    form->addRow("Personaggio", type);

    //level
    level=new QSpinBox();
    level->setMinimum(1);
    level->setMaximum(4);
    level->setSingleStep(1);
    level->setValue(1);
    form->addRow("Livello", level);

    //button
    QPushButton* button = new QPushButton("X");
    hbox->addWidget(button);
    
    //connect
    connect(button, &QPushButton::pressed, this, &CharacterWidget::removeCharacter);
}

void CharacterWidget::removeCharacter(){
    emit remove(this);
}

bool CharacterWidget::isReady() const{
    return true;
}

QString CharacterWidget::getTypeText() const{
    return type->itemText(type->currentIndex());
}

int CharacterWidget::getLevelValue() const{
    return level->value();
}

QComboBox* CharacterWidget::getTypeWidget() const{
    return type;
}

QSpinBox* CharacterWidget::getLevelWidget() const{
    return level;
}

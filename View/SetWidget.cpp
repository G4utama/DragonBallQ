#include "SetWidget.h"
#include "CharacterWidget.h"
//QT
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QVector>

SetWidget::SetWidget(QWidget* parent): QWidget(parent){
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    //vector
    characterVector.push_back(new CharacterWidget(this));
    layout->addWidget(characterVector[0]);

    //button
    button = new QPushButton("+ Personaggio");
    layout->addWidget(button);
    
    //connect
    connect(characterVector[0], &CharacterWidget::remove, this, &SetWidget::removeCharacter);
    connect(button, &QPushButton::pressed, this, &SetWidget::addCharacter);
}

bool SetWidget::isReady() const{
    if(characterVector.isEmpty()){
        return false;
    }
    for(auto it=characterVector.begin(); it!=characterVector.end(); ++it){
        if(!((*it)->isReady())){
            return false;
        }  
    }
    return true;
}

QVector<CharacterWidget*> SetWidget::getCharacterVector() const{
    return characterVector;
}

void SetWidget::clear() {
    while(!characterVector.isEmpty()) {
        layout->removeWidget(characterVector.last());
        delete characterVector.last();
        characterVector.removeLast();
    }
}

void SetWidget::addCharacter(){
    layout->removeWidget(button);
    characterVector.push_back(new CharacterWidget(this));
    layout->addWidget(characterVector[characterVector.size()-1]);
    layout->addWidget(button);
    connect(characterVector[characterVector.size()-1], &CharacterWidget::remove, this, &SetWidget::removeCharacter);
}

void SetWidget::removeCharacter(CharacterWidget* target){
    layout->removeWidget(target);
    characterVector.removeOne(target);
    delete target;
}
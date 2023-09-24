#include "SaiyajinPanel.h"
#include "Info.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QString>
#include <QVector>
#include <QLabel>

SaiyajinPanel::SaiyajinPanel(CharacterSet& s, QWidget* p): QWidget(p), set(s){
    layout=new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //buttons
    QGridLayout* buttons = new QGridLayout();
    layout->addLayout(buttons);
    QPushButton* attack = new QPushButton("Attacco");
    attack->setFixedHeight(50);
    buttons->addWidget(attack, 0, 0, 1, 1);
    QPushButton* change = new QPushButton("Cambio");
    change->setFixedHeight(50);
    buttons->addWidget(change, 0, 1, 1, 1);

    //artoworks
    art = new QHBoxLayout();
    layout->addLayout(art);
    for(auto it=s.begin(); it!=s.end(); ++it){
        QPixmap image(QString::fromStdString((*it)->getArtwork()));
        QLabel* artwork=new QLabel();
        artwork->setPixmap(image.scaledToHeight(200));
        artVector.push_back(artwork);
        art->addWidget(artwork);
    }
    
    //info
    info=new Info(s.search(0));
    info->show();
    layout->addWidget(info);

    //connect
    connect(attack, &QPushButton::pressed, this, &SaiyajinPanel::attack);
    connect(change, &QPushButton::pressed, this, &SaiyajinPanel::switchCharacter);

    //observer
    set.registerObserver(this);
}

void SaiyajinPanel::notify(CharacterSet& set){
    //artwork
    for(auto it=artVector.begin(); it!=artVector.end(); ++it){
        layout->removeWidget(*it);
        delete *it;
    }
    artVector.resize(0);
    for(auto it=set.begin(); it!=set.end(); ++it){
        QLabel* artwork = new QLabel();
        QPixmap image(QString::fromStdString((*it)->getArtwork()));
        if((*it)->isAlive()){
            artwork->setPixmap(image.scaledToHeight(200));
        }else{
            artwork->setPixmap(image.scaledToHeight(100));
        }
        artVector.push_back(artwork);
        art->addWidget(artwork);
    }

    //info
    set.search(set.getAlive()-1)->removeObserver(info);
    layout->removeWidget(info);
    delete info;
    info = new Info(set.search(0));
    info->show();
    layout->addWidget(info);
}

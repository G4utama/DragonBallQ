#include "EnemyPanel.h"
#include "Info.h"
#include "../Character/CharacterSetObserver.h"
//QT
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QString>
#include <QVector>
#include <QLabel>
#include <iostream>

EnemyPanel::EnemyPanel(CharacterSet& s, QWidget* p): QWidget(p), set(s){
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    
    //artwork
    art = new QHBoxLayout();
    layout->addLayout(art);
    for(auto it=s.begin(); it!=s.end(); ++it) {
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
    
    //observer
    set.registerObserver(this);
}

void EnemyPanel::notify(CharacterSet& set){
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

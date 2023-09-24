#include "Game.h"
//QT
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>

Game::Game(CharacterSet& sSet, CharacterSet& eSet, QWidget* p): QWidget(p), saiyajinSet(sSet), enemySet(eSet){
    QHBoxLayout* layout = new QHBoxLayout(this);

    saiyajinPanel = new SaiyajinPanel(saiyajinSet);
    layout->addWidget(saiyajinPanel);

    layout->addStretch();

    enemyPanel = new EnemyPanel(enemySet);
    layout->addWidget(enemyPanel);

    connect(saiyajinPanel, &SaiyajinPanel::attack, this, &Game::attackCharacter);
    connect(saiyajinPanel, &SaiyajinPanel::switchCharacter, this, &Game::switchCharacter);
}

void Game::attackCharacter(){
    bool b = false;
    if(enemySet.getAlive()>0){
        (saiyajinSet.search(0))->attack(enemySet);
        if(enemySet.getAlive()<=0){
            emit endGame(true);
            b = true;
        }
    }
    if(!b && saiyajinSet.getAlive()>0){
        (enemySet.search(0))->attack(saiyajinSet);
        if(saiyajinSet.getAlive()<=0){
            emit endGame(false);
        }
    }
}

void Game::switchCharacter(){
    saiyajinSet.moveAlive();
}

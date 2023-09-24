#ifndef GAME_H
#define GAME_H

#include "../Character/CharacterSet.h"
#include "SaiyajinPanel.h"
#include "EnemyPanel.h"
//QT
#include <QWidget>

class Game: public QWidget{
Q_OBJECT
private:
    CharacterSet saiyajinSet;
    CharacterSet enemySet;
    SaiyajinPanel* saiyajinPanel;
    EnemyPanel* enemyPanel;
public:
    Game(CharacterSet& saiyajinSet, CharacterSet& enemySet, QWidget* parent=0);
public slots:
    void attackCharacter();
    void switchCharacter();
signals:
    void close();
    void endGame(bool);
};

#endif
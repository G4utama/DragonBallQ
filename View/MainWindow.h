#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "SetWidget.h"
#include "Game.h"
#include "../Character/CharacterSet.h"
//QT
#include <QMainWindow>
#include <QWidget>
#include <QToolBar>
#include <QSplitter>
#include <QStackedWidget>
#include <QString>

class MainWindow: public QMainWindow{
Q_OBJECT
private:
    QStackedWidget* stackedWidget;
    Game* game;

    bool isSalvable;
    bool isPlayable;

    CharacterSet& saiyajinSet;
    CharacterSet& enemySet;
    SetWidget* saiyajinWidget;
    SetWidget* enemyWidget;

    void refresh(SetWidget* setWidget, CharacterSet& set);
    void clearStack();
public:
    MainWindow(CharacterSet& saiyajin, CharacterSet& enemy, QWidget* parent=0);
    virtual ~MainWindow() {}
public slots:
    void loadGame();
    void saveGame();
    void startGame();
    void clear();
    void close();
    void endGame(bool);
};

#endif

#include "MainWindow.h"
#include "Game.h"
//Character
#include "../Character/CharacterSet.h"
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
#include "../Character/MajinBuu.h"
#include "CharacterWidgetVisitor.h"
//Json
#include "../Json/Json.h"
#include "../Json/JsonVisitor.h"
//QT
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QAction>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QSplitter>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QVector>
#include <QFileDialog>

MainWindow::MainWindow(CharacterSet& saiyajin, CharacterSet& enemy, QWidget* parent): QMainWindow(parent), isSalvable(true), isPlayable(false), saiyajinSet(saiyajin), enemySet(enemy){
    //menu
    QMenu* menu = menuBar()->addMenu("Menu");
    QAction* carica = new QAction("Carica");
    carica->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    menu->addAction(carica);

    QAction* salva = new QAction("Salva");
    salva->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    menu->addAction(salva);

    menu->addSeparator();

    QAction* gioca = new QAction("Gioca");
    gioca->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
    menu->addAction(gioca);

    QAction* chiudi = new QAction("Chiudi");
    chiudi->setShortcut(QKeySequence(Qt::Key_Escape));
    menu->addAction(chiudi);

    //connect
    connect(carica, &QAction::triggered, this, &MainWindow::loadGame);
    connect(salva, &QAction::triggered, this, &MainWindow::saveGame);
    connect(gioca, &QAction::triggered, this, &MainWindow::startGame);
    connect(chiudi, &QAction::triggered, this, &MainWindow::close);

    //stackedWidget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    QSplitter* splitter = new QSplitter(this);
    stackedWidget->addWidget(splitter);

    saiyajinWidget = new SetWidget(this);
    splitter->addWidget(saiyajinWidget);
    enemyWidget = new SetWidget(this);
    splitter->addWidget(enemyWidget);
}

void MainWindow::clearStack(){
    QWidget* widget=stackedWidget->widget(1);
    while(widget){
        stackedWidget->removeWidget(widget);
        delete widget;
        widget=stackedWidget->widget(1);
    }
}

void MainWindow::loadGame(){
    if(isPlayable){
        QMessageBox::warning(this, "Errore", "Impossibile caricare!", QMessageBox::Ok);
        return;
    }
    isSalvable = false;
    QString url = QFileDialog::getOpenFileName(this, "Scegli il file", "./", "JSON files *.json");
    if(url.isEmpty()) {
        isSalvable = true;
        return;
    }
    Json::load(url, saiyajinSet, enemySet);

    saiyajinWidget->clear();
    enemyWidget->clear();

    for(auto it=saiyajinSet.begin(); it!=saiyajinSet.end(); ++it){
        saiyajinWidget->addCharacter();
        CharacterWidgetVisitor visitor(saiyajinWidget->getCharacterVector().last());
        (*it)->accept(visitor);
    }
    for(auto it=enemySet.begin(); it!=enemySet.end(); ++it){
        enemyWidget->addCharacter();
        CharacterWidgetVisitor visitor(enemyWidget->getCharacterVector().last());
        (*it)->accept(visitor);
    }
    isSalvable = true;
}

void MainWindow::refresh(SetWidget* setWidget, CharacterSet& set){
    QVector<CharacterWidget*> setVector = setWidget->getCharacterVector();
    set = CharacterSet(setVector.size());
    Character* character;
    for(auto it=setVector.begin(); it!=setVector.end(); ++it){
        if((*it)->getTypeText()=="Goku"){
            if((*it)->getLevelValue()==1){
                character = new Goku("Goku", 100, 40, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Goku1.png");
            }else if((*it)->getLevelValue()==2){
                character = new Goku("Goku", 110, 35, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Goku2.png");
            }else if((*it)->getLevelValue()==3){
                character = new Goku("Goku", 120, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Goku3.png");
            }else{ //else if((*it)->getLevelValue()==4){
                character = new Goku("Goku", 130, 25, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Goku4.png");
            }
        }else if((*it)->getTypeText()=="Vegeta"){
            if((*it)->getLevelValue()==1){
                character = new Vegeta("Vegeta", 100, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Vegeta1.png");
            }else if((*it)->getLevelValue()==2 || (*it)->getLevelValue()==3){
                character = new Vegeta("Vegeta", 110, 25, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Vegeta2.png");
            }else{ //else if((*it)->getLevelValue()==4){
                character = new Vegeta("Vegeta", 120, 20, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Vegeta3.png");
            }
        }else if((*it)->getTypeText()=="Trunks"){
            if((*it)->getLevelValue()==1){
                character = new Trunks("Trunks", 100, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Trunks1.png");
            }else{ //else if((*it)->getLevelValue()>=2){
                character = new Trunks("Trunks", 100, 20, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Trunks2.png");
            }  
        }else if((*it)->getTypeText()=="Gohan"){
            if((*it)->getLevelValue()==1){
                character = new Gohan("Gohan", 90, 40, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Gohan1.png");
            }else{ //else if((*it)->getLevelValue()>=2){
                character = new Gohan("Gohan", 100, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Gohan2.png");
            } 
        }else if((*it)->getTypeText()=="Freezer"){
            if((*it)->getLevelValue()==1){
                character = new Freezer("Freezer", 90, 40, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Freezer1.png");
            }else if((*it)->getLevelValue()==2){
                character = new Freezer("Freezer", 100, 35, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Freezer2.png");
            }else if((*it)->getLevelValue()==3){
                character = new Freezer("Freezer", 100, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Freezer3.png");
            }else{ //else if((*it)->getLevelValue()==4){
                character = new Freezer("Freezer", 100, 25, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Freezer4.png");
            }  
        }else if((*it)->getTypeText()=="Cell"){
            if((*it)->getLevelValue()==1){
                character = new Cell("Cell", 90, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Cell1.png");
            }else if((*it)->getLevelValue()==2){
                character = new Cell("Cell", 100, 25, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Cell2.png");
            }else{ //else if((*it)->getLevelValue()>=3){
                character = new Cell("Cell", 100, 20, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/Cell3.png");
            }
        }else{ //else if((*it)->getTypeText()=="MajinBuu"){
            if((*it)->getLevelValue()==1){
                character = new MajinBuu("MajinBuu", 110, 35, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/MajinBuu1.png");
            }else if((*it)->getLevelValue()==2){
                character = new MajinBuu("MajinBuu", 120, 30, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/MajinBuu2.png");
            }else if((*it)->getLevelValue()==3){
                character = new MajinBuu("MajinBuu", 130, 25, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/MajinBuu3.png");
            }else{ //else if((*it)->getLevelValue()==4){
                character = new MajinBuu("MajinBuu", 150, 20, static_cast<unsigned int>((*it)->getLevelValue()), "Artwork/MajinBuu4.png");
            }
        }
        set.insertBack(character);
    }
}

void MainWindow::saveGame(){
    if(!isSalvable){
        QMessageBox::warning(this, "Errore", "Impossibile salvare!", QMessageBox::Ok);
        return;
    }
    QString url = QFileDialog::getSaveFileName(this, "Salva", "./", "JSON files *.json");
    if(url.isEmpty()){
        return;
    }
    refresh(saiyajinWidget, saiyajinSet);
    refresh(enemyWidget, enemySet);
    Json::save(url, saiyajinSet, enemySet);
}

void MainWindow::startGame(){
    if(!(saiyajinWidget->isReady() && enemyWidget->isReady()) || isPlayable){
        QMessageBox::warning(this, "Errore", "Riprovare", QMessageBox::Ok);
        return;
    }
    refresh(saiyajinWidget, saiyajinSet);
    refresh(enemyWidget, enemySet);
    isSalvable = false;
    isPlayable = true;

    game = new Game(saiyajinSet, enemySet, this);
    stackedWidget->addWidget(game);
    stackedWidget->setCurrentIndex(1);

    connect(game, &Game::close, this, &MainWindow::clear);
    connect(game, &Game::endGame, this, &MainWindow::endGame);
}

void MainWindow::clear(){
    clearStack();
    isSalvable = true;
    isPlayable = false;
}

void MainWindow::close(){
    QMessageBox::StandardButton esc = QMessageBox::question(this, "Chiudi", "I progressi non salvati verranno cancellati\nChiudere comunque?", QMessageBox::Yes | QMessageBox::No);
    if(esc == QMessageBox::Yes){
        QApplication::quit();
    }
}

void MainWindow::endGame(bool isWin){
    QMessageBox::StandardButton end;
    if(isWin){
        end = QMessageBox::question(this, "Vinto", "Chiudere?", QMessageBox::Yes | QMessageBox::No);
    }else{
        end = QMessageBox::question(this, "Perso", "Chiudere?", QMessageBox::Yes | QMessageBox::No);
    }
    if(end == QMessageBox::Yes){
        QApplication::quit();
    }else{
        clearStack();
        isSalvable = true;
        isPlayable = false;
    } 
}
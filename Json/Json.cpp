#include "JsonVisitor.h"
#include "Json.h"
//Character
#include "../Character/CharacterSet.h"
#include "../Character/Goku.h"
#include "../Character/Vegeta.h"
#include "../Character/Trunks.h"
#include "../Character/Gohan.h"
#include "../Character/Freezer.h"
#include "../Character/Cell.h"
#include "../Character/MajinBuu.h"
//QT
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QJsonValue>

void Json::save(const QString& url, const CharacterSet& saiyajinSet, const CharacterSet& enemySet){
    QJsonArray jsonArray;
    QJsonArray jsonSayanjinSet;
    QJsonArray jsonEnemySet;
    JsonVisitor jsonVisitor;
    //salva sullo stesso file json prima il team degli alleati e poi quello dei nemici, su due QJsonArray differenti
    for(auto it=saiyajinSet.begin(); it!=saiyajinSet.end(); ++it){
        (*it)->accept(jsonVisitor);
        jsonSayanjinSet.push_back(jsonVisitor.getContent());
    }
    for(auto it=enemySet.begin(); it!=enemySet.end(); ++it){
        (*it)->accept(jsonVisitor);
        jsonEnemySet.push_back(jsonVisitor.getContent());
    }
    jsonArray.push_back(jsonSayanjinSet);
    jsonArray.push_back(jsonEnemySet);
    if(!url.isEmpty()) {
        QJsonDocument document(jsonArray);
        QFile jsonFile(url);
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(document.toJson());
        jsonFile.close();
    }
}

void Json::loadTeam(CharacterSet& set, const QJsonArray& jsonSet){
    Character* character;
    for(auto it=jsonSet.begin(); it!=jsonSet.end(); ++it){
        QJsonObject object=it->toObject();
        if(object.value("type").toString().compare("goku")==0){
            if(object.value("level").toInt()==1){
                character = new Goku("Goku", 100, 40, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Goku1.png");
            }else if(object.value("level").toInt()==2){
                character = new Goku("Goku", 110, 35, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Goku2.png");
            }else if(object.value("level").toInt()==3){
                character = new Goku("Goku", 120, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Goku3.png");
            }else{
                character = new Goku("Goku", 130, 25, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Goku4.png");
            }
        }else if(object.value("type").toString().compare("vegeta")==0){
            if(object.value("level").toInt()==1){
                character = new Vegeta("Vegeta", 100, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Vegeta1.png");
            }else if(object.value("level").toInt()==2 || object.value("level").toInt()==3){
                character = new Vegeta("Vegeta", 110, 25, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Vegeta2.png");
            }else{
                character = new Vegeta("Vegeta", 120, 20, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Vegeta3.png");
            }
        }else if(object.value("type").toString().compare("trunks")==0){
            if(object.value("level").toInt()==1){
                character = new Trunks("Trunks", 100, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Trunks1.png");
            }else{
                character = new Trunks("Trunks", 100, 20, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Trunks2.png");
            }
        }else if(object.value("type").toString().compare("gohan")==0){
            if(object.value("level").toInt()==1){
                character = new Gohan("Gohan", 90, 40, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Gohan1.png");
            }else{
                character = new Gohan("Gohan", 100, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Gohan2.png");
            }
        }else if(object.value("type").toString().compare("freezer")==0){
            if(object.value("level").toInt()==1){
                character = new Freezer("Freezer", 90, 40, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Freezer1.png");
            }else if(object.value("level").toInt()==2){
                character = new Freezer("Freezer", 100, 35, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Freezer2.png");
            }else if(object.value("level").toInt()==3){
                character = new Freezer("Freezer", 100, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Freezer3.png");
            }else{
                character = new Freezer("Freezer", 100, 25, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Freezer4.png");
            }
        }else if(object.value("type").toString().compare("cell")==0){
            if(object.value("level").toInt()==1){
                character = new Cell("Cell", 90, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Cell1.png");
            }else if(object.value("level").toInt()==2){
                character = new Cell("Cell", 100, 25, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Cell2.png");
            }else{
                character = new Cell("Cell", 100, 20, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/Cell3.png");
            }            
        }else{ //else if(object.value("type").toString().compare("majinbuu")==0){
            if(object.value("level").toInt()==1){
                character = new MajinBuu("MajinBuu", 100, 35, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/MajinBuu1.png");
            }else if(object.value("level").toInt()==2){
                character = new MajinBuu("MajinBuu", 120, 30, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/MajinBuu2.png");
            }else if(object.value("level").toInt()==3){
                character = new MajinBuu("MajinBuu", 130, 25, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/MajinBuu3.png");
            }else{
                character = new MajinBuu("MajinBuu", 150, 20, static_cast<unsigned int>(object.value("level").toInt()), "../Artwork/MajinBuu4.png");
            }
        }
        set.insertBack(character);
    }
}

void Json::load(const QString& url, CharacterSet& saiyajinSet, CharacterSet& enemySet){
    QFile jsonFile(url);
    jsonFile.open(QFile::ReadOnly);
    QByteArray data = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument document=QJsonDocument::fromJson(data);
    QJsonArray jsonArray = document.array();
    QJsonArray jsonSayanjinSet = jsonArray[0].toArray();
    QJsonArray jsonEnemySet = jsonArray[1].toArray();

    saiyajinSet=CharacterSet(jsonSayanjinSet.size());
    enemySet=CharacterSet(jsonEnemySet.size());

    loadTeam(saiyajinSet, jsonSayanjinSet);
    loadTeam(enemySet, jsonEnemySet);
}

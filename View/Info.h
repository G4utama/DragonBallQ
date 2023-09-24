#ifndef INFO_H
#define INFO_H
//Character
#include "../Character/Character.h"
#include "../Character/CharacterObserver.h"
//QT
#include <QWidget>
#include <QLabel>

class Info: public QWidget, public CharacterObserver{
Q_OBJECT
private:
    Character* character;
    QLabel* name;
    QLabel* hp;
    QLabel* att;
    QLabel* level;
    QLabel* attack;
public:
    Info(Character* character, QWidget* parent=0);
    void show();
    void notify(Character& character) override;
    QLabel* getNameWidget() const;
    QLabel* getHpWidget() const;
    QLabel* getAttWidget() const;
    QLabel* getLevelWidget() const;
    QLabel* getAttackWidget() const;
};

#endif

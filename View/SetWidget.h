#ifndef SET_WIDGET_H
#define SET_WIDGET_H

#include "../Character/CharacterSet.h"
#include "CharacterWidget.h"
//QT
#include <QLineEdit>
#include <QSpinBox>
#include <QVector>
#include <QPushButton>
#include <QVBoxLayout>

class SetWidget: public QWidget{
Q_OBJECT
private:
    QVBoxLayout* layout;
    QPushButton* button;
    QVector<CharacterWidget*> characterVector;
public:
    explicit SetWidget(QWidget* parent = 0);
    bool isReady() const; //serve per vedere se il gioco è pronto e ci sono almeno 2 personaggi
    void clear();
    //get
    QVector<CharacterWidget*> getCharacterVector() const;
public slots:
    void addCharacter();
    void removeCharacter(CharacterWidget*);
};

#endif
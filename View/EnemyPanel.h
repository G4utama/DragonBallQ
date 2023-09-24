#ifndef ENEMY_PANEL_H
#define ENEMY_PANEL_H

#include "Info.h"
//Character
#include "../Character/CharacterSet.h"
#include "../Character/CharacterSetObserver.h"
//QT
#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>

class EnemyPanel: public QWidget, public CharacterSetObserver{
Q_OBJECT
private:
    CharacterSet& set;
    QVector<QLabel*> artVector;
    Info* info;
    QVBoxLayout* layout;
    QHBoxLayout* art;
public:
    explicit EnemyPanel(CharacterSet& set, QWidget* parent=0);
    void notify(CharacterSet& set) override;
};

#endif
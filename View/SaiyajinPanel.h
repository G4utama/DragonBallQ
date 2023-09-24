#ifndef SAIYAJIN_PANEL_H
#define SAIYAJIN_PANEL_H

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

class SaiyajinPanel: public QWidget, public CharacterSetObserver{
Q_OBJECT
private:
    CharacterSet& set;
    QVector<QLabel*> artVector;
    Info* info;
    QVBoxLayout* layout;
    QHBoxLayout* art;
public:
    explicit SaiyajinPanel(CharacterSet& set, QWidget* parent=0);
    void notify(CharacterSet& set) override;
signals:
    void attack();
    void switchCharacter();
};

#endif

#ifndef CHARACTER_WIDGET_H
#define CHARACTER_WIDGET_H

//QT
#include <QLineEdit>
#include <QSpinBox>
#include <QString>
#include <QComboBox>

class CharacterWidget: public QFrame{
Q_OBJECT
private:
    QComboBox* type;
    QLineEdit* name;
    QSpinBox* level;

public:
    explicit CharacterWidget(QWidget* parent = 0);
    bool isReady() const;

    QString getTypeText() const;
    int getLevelValue() const;
    
    QComboBox* getTypeWidget() const;
    QSpinBox* getLevelWidget() const;
signals:
    void remove(CharacterWidget*);

public slots:
    void removeCharacter();
};

#endif

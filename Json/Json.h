#ifndef JSON_H
#define JSON_H

#include <QString>
#include "../Character/CharacterSet.h"

class Json{
private:
    static void loadTeam(CharacterSet& set, const QJsonArray& jsonSet);
public:
    Json()=delete;
    Json(const Json&)=delete;
    static void save(const QString& url, const CharacterSet& saiyajinSet, const CharacterSet& enemySet);
    static void load(const QString& url, CharacterSet& saiyajinSet, CharacterSet& enemySet);
};

#endif
#ifndef TEXTADV_ENEMYOBJECT_H
#define TEXTADV_ENEMYOBJECT_H

#include <string>

class EnemyObject {
public:
    int health;
    std::string keyword;
    EnemyObject(int h, const std::string& k) : health(h), keyword(k) {}
    virtual void damage(int amount) = 0;
    virtual ~EnemyObject() {}
    virtual int getHealth() const {
        return health;
    }
};

#endif //TEXTADV_ENEMYOBJECT_H
#ifndef TEXTADV_BOSS_H
#define TEXTADV_BOSS_H

#include <iostream>
#include "EnemyObject.h"

class Boss : public EnemyObject {
public:
    Boss() : EnemyObject(100, "Boss") {}
    void damage(int amount) override {
        health -= amount;
        if (health <= 0) {
            std::cout << "Boss is defeated!" << std::endl;
        }
    }
};

#endif //TEXTADV_BOSS_H
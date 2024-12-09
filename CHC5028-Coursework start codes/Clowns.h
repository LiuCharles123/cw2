#ifndef TEXTADV_CLOWNS_H
#define TEXTADV_CLOWNS_H

#include "EnemyObject.h"

class Clowns : public EnemyObject {
public:
    Clowns() : EnemyObject(30, "Clowns") {}
    void damage(int amount) override {
        health -= amount;
        if (health <= 0) {
            std::cout << "Clowns are defeated!" << std::endl;
        }
    }
};

#endif //TEXTADV_CLOWNS_H
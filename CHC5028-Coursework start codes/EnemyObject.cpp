#include "EnemyObject.h"

EnemyObject::EnemyObject(const std::string& _keyword, double _weight, int _health)
        : GameObject(_keyword, _weight), health(_health) {}

int EnemyObject::getHealth() const {
    return health;
}

void EnemyObject::damage(int amount) {
    health -= amount;
    if (health <= 0) {
        health = 0;
    }
}
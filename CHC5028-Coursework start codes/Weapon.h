#ifndef TEXTADV_WEAPON_H
#define TEXTADV_WEAPON_H

#include "GameObject.h"

class Weapon : public GameObject {
public:
    int harm;
    Weapon(float w, const std::string& k, int h) : GameObject(w, k), harm(h) {}
    std::string getType() const override {
        return "weapon";
    }
};

#endif //TEXTADV_WEAPON_H
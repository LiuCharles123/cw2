#ifndef TEXTADV_FOOD_H
#define TEXTADV_FOOD_H

#include "GameObject.h"

class Food : public GameObject {
public:
    int energy;
    Food(float w, const std::string& k, int e) : GameObject(w, k), energy(e) {}
    std::string getType() const override {
        return "food";
    }
};

#endif //TEXTADV_FOOD_H
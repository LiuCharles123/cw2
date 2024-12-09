#include "Food.h"
#include <iostream>

Food::Food(const std::string& _keyword, double _weight, int _energy) : GameObject(_keyword, _weight), energy(_energy) {}

std::string Food::getDescription() const {
    return "This is food named " + getKeyword() + " with a weight of " + std::to_string(getWeight()) + " and provides " + std::to_string(getEnergy()) + " points of energy.";
}

int Food::getEnergy() const {
    return energy;
}
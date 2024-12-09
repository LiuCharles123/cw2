#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& _keyword, double _weight, int _harm) : GameObject(_keyword, _weight), harm(_harm) {}

std::string Weapon::getDescription() const {
    return "This is a weapon named " + getKeyword() + " with a weight of " + std::to_string(getWeight()) + " and can cause " + std::to_string(getHarm()) + " points of harm.";
}

int Weapon::getHarm() const {
    return harm;
}
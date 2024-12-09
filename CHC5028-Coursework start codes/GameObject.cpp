#include "GameObject.h"

GameObject::GameObject(const std::string& _keyword, double _weight) : keyword(_keyword), weight(_weight) {}

std::string GameObject::getKeyword() const {
    return keyword;
}

double GameObject::getWeight() const {
    return weight;
}
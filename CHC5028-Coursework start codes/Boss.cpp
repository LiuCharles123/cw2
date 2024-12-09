#include "Boss.h"
#include <iostream>

void Boss::describe() const {
    std::cout << "A fearsome boss with " << getHealth() << " health points stands before you." << std::endl;
}
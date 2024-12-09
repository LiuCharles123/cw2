#include "Clowns.h"
#include <iostream>

void Clowns::describe() const {
    std::cout << "A silly clown with " << getHealth() << " health points tries to tickle you." << std::endl;
}
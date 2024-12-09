#include "State.h"
#include "wordwrap.h"
#include <fstream>
#include <sstream>
#include <iostream>

State::State(Room* startRoom) : currentRoom(startRoom), strength(100) {}

State::~State() {
    for (auto obj : inventory) {
        delete obj;
    }
}

void State::announceLoc() const {
    currentRoom->describe();
}

void State::goTo(Room* target) {
    this->currentRoom = target;
    this->announceLoc();
}

Room* State::getCurrentRoom() const {
    return this->currentRoom;
}

void State::reduceStrength(int amount) {
    strength -= amount;
    if (strength <= 0) {
        std::cout << "Your strength has reached 0. You have died." << std::endl;
        exit(0);
    }
}

int State::getStrength() const {
    return strength;
}

void State::addInventory(GameObject* obj) {
    inventory.push_back(obj);
}

GameObject* State::getInventoryItem(const std::string& keyword) {
    for (auto obj : inventory) {
        if (obj->keyword == keyword) {
            return obj;
        }
    }
    return nullptr;
}

void State::removeInventoryItem(GameObject* obj) {
    inventory.remove_if([obj](const GameObject* o) { return o == obj; });
    delete obj;
}

void State::describeInventory() const {
    if (inventory.empty()) {
        wrapOut("You have nothing in your inventory.");
    } else {
        wrapOut("Your inventory:");
        for (const auto& obj : inventory) {
            wrapOut(obj->keyword);
        }
    }
    wrapEndPara();
}

void State::save(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Unable to open file for saving." << std::endl;
        return;
    }
    outFile << "strength=" << strength << "\n";
    outFile << "current_room=" << currentRoom << "\n";
    outFile << "inventory_size=" << inventory.size() << "\n";
    for (const auto& obj : inventory) {
        outFile << obj->getType() << " " << obj->getKeyword() << "\n";
    }
}

State State::load(const std::string& filename, Room* startRoom) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file for loading." << std::endl;
        return State(startRoom);
    }
    State loadedState(startRoom);
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.substr(0, 9) == "strength=") {
            loadedState.strength = std::stoi(line.substr(10));
        } else if (line.substr(0, 12) == "current_room=") {
            // Handle current room loading
        } else if (line.substr(0, 14) == "inventory_size=") {
            int size = std::stoi(line.substr(15));
            for (int i = 0; i < size; ++i) {
                std::string type, keyword;
                std::getline(inFile, type);
                std::getline(inFile, keyword);
                if (type == "weapon") {
                    loadedState.addInventory(new Weapon(5.0, keyword, 10)); // Example
                } else if (type == "food") {
                    loadedState.addInventory(new Food(2.0, keyword, 5)); // Example
                }
            }
        }
    }
    return loadedState;
}
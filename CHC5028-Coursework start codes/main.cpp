#include <iostream>
#include <string>
#include <fstream>
#include "Room.h"
#include "State.h"
#include "wordwrap.h"
#include "strings.h"

using std::string;
using std::ifstream;
using std::ofstream;

State* currentState;
std::list<Room*> Room::rooms;

void inputCommand(string* buffer) {
    buffer->clear();
    std::cout << "> ";
    std::getline(std::cin, *buffer);
}

void initRooms() {
    auto *r1 = new Room(&r1name, &r1desc);
    auto *r2 = new Room(&r2name, &r2desc);
    Room room3(&r1name, &r1desc);
    Room* r3 = &room3;

    r1->setNorth(r2);
    r2->setSouth(r1);
    r1->setEast(r3);
    r3->setWest(r1);

    Room::addRoom(r1);
    Room::addRoom(r2);
    Room::addRoom(r3);

    r1->addObject(new Weapon(5.0, "Sword", 15));
    r2->addObject(new Food(2.0, "Apple", 5));

    r1->addEnemy(new Boss());
    r2->addEnemy(new Clowns());
}

void initState() {
    currentState = new State(Room::rooms.front());
}

void gameLoop() {
    bool gameOver = false;
    while (!gameOver) {
        string commandBuffer;
        inputCommand(&commandBuffer);

        size_t firstSpace = commandBuffer.find(' ');
        string verb, noun;
        if (firstSpace != string::npos) {
            verb = commandBuffer.substr(0, firstSpace);
            noun = commandBuffer.substr(firstSpace + 1);
        } else {
            verb = commandBuffer;
            noun = "";
        }

        if (verb == "north" || verb == "n") {
            Room* northRoom = currentState->getCurrentRoom()->getNorth();
            if (northRoom) {
                currentState->goTo(northRoom);
            } else {
                wrapOut(&badExit);
            }
        } else if (verb == "south" || verb == "s") {
            Room* southRoom = currentState->getCurrentRoom()->getSouth();
            if (southRoom) {
                currentState->goTo(southRoom);
            } else {
                wrapOut(&badExit);
            }
        } else if (verb == "east" || verb == "e") {
            Room* eastRoom = currentState->getCurrentRoom()->getEast();
            if (eastRoom) {
                currentState->goTo(eastRoom);
            } else {
                wrapOut(&badExit);
            }
        } else if (verb == "west" || verb == "w") {
            Room* westRoom = currentState->getCurrentRoom()->getWest();
            if (westRoom) {
                currentState->goTo(westRoom);
            } else {
                wrapOut(&badExit);
            }
        } else if (verb == "get" && !noun.empty()) {
            GameObject* obj = currentState->getCurrentRoom()->getObject(noun);
            if (obj) {
                currentState->addInventory(obj);
                currentState->getCurrentRoom()->removeObject(obj);
            } else {
                wrapOut("Object not found.");
            }
        } else if (verb == "drop" && !noun.empty()) {
            GameObject* obj = currentState->getInventoryItem(noun);
            if (obj) {
                currentState->removeInventoryItem(obj);
                currentState->getCurrentRoom()->addObject(obj);
            } else {
                wrapOut("Object not found in inventory.");
            }
        } else if (verb == "inventory") {
            currentState->describeInventory();
        } else if (verb == "eat" && !noun.empty()) {
            GameObject* food = currentState->getInventoryItem(noun);
            if (dynamic_cast<Food*>(food)) {
                Food* f = dynamic_cast<Food*>(food);
                currentState->reduceStrength(f->energy);
                currentState->removeInventoryItem(food);
                delete food;
            } else {
                wrapOut("You can't eat that.");
            }
        } else if (verb == "fight" && !noun.empty()) {
            EnemyObject* enemy = currentState->getCurrentRoom()->getEnemy(noun);
            if (enemy) {
                int playerStrength = currentState->getStrength();
                enemy->damage(playerStrength);
                currentState->reduceStrength(10); // Simplified enemy attack
                if (enemy->getHealth() <= 0) {
                    currentState->getCurrentRoom()->removeEnemy(enemy);
                    delete enemy;
                    wrapOut("Enemy defeated.");
                } else {
                    wrapOut("Enemy still stands.");
                }
            } else {
                wrapOut("No enemy found.");
            }
        } else if (verb == "save") {
            currentState->save("savegame.txt");
            wrapOut("Game saved.");
        } else if (verb == "load") {
            delete currentState;
            currentState = State::load("savegame.txt", Room::rooms.front());
            currentState->announceLoc();
            wrapOut("Game loaded.");
        } else if (verb == "quit") {
            gameOver = true;
        } else {
            wrapOut(&badCommand);
        }
    }
}

int main() {
    initWordWrap();
    initRooms();
    initState();
    currentState->announceLoc();
    gameLoop();
    return 0;
}
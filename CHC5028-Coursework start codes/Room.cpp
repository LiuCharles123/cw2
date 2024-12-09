#include "Room.h"
#include "wordwrap.h"

std::list<Room*> Room::rooms;

Room::Room(const std::string* _name, const std::string* _desc) :
        name(_name), description(_desc), north(nullptr), east(nullptr), south(nullptr), west(nullptr) {}

Room::~Room() {
    Room::rooms.remove(this);
    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();
    for (auto enemy : enemies) {
        delete enemy;
    }
    enemies.clear();
}

void Room::describe() const {
    wrapOut(name);
    wrapEndPara();
    wrapOut(description);
    wrapEndPara();
    describeObjects();
}

Room* Room::addRoom(const string* _name, const string* _desc) {
    auto *newRoom = new Room(_name, _desc);
    Room::rooms.push_back(newRoom);
    return newRoom;
}

void Room::addRoom(Room* room) {
    Room::rooms.push_back(room);
}

Room* Room::getNorth() const {
    return north;
}

void Room::setNorth(Room* _north) {
    north = _north;
}

Room* Room::getEast() const {
    return east;
}

void Room::setEast(Room* _east) {
    east = _east;
}

Room* Room::getSouth() const {
    return south;
}

void Room::setSouth(Room* _south) {
    south = _south;
}

Room* Room::getWest() const {
    return west;
}

void Room::setWest(Room* _west) {
    west = _west;
}

void Room::addObject(GameObject* obj) {
    objects.push_back(obj);
}

GameObject* Room::getObject(const std::string& keyword) {
    for (auto obj : objects) {
        if (obj->keyword == keyword) {
            return obj;
        }
    }
    return nullptr;
}

void Room::removeObject(GameObject* obj) {
    objects.remove_if([obj](const GameObject* o) { return o == obj; });
    delete obj;
}

void Room::addEnemy(EnemyObject* enemy) {
    enemies.push_back(enemy);
}

EnemyObject* Room::getEnemy(const std::string& keyword) {
    for (auto enemy : enemies) {
        if (enemy->keyword == keyword) {
            return enemy;
        }
    }
    return nullptr;
}

void Room::removeEnemy(EnemyObject* enemy) {
    enemies.remove_if([enemy](const EnemyObject* e) { return e == enemy; });
    delete enemy;
}

void Room::describeObjects() const {
    if (objects.empty()) return;
    wrapOut("Objects in the room:");
    wrapEndPara();
    for (const auto& obj : objects) {
        wrapOut(obj->keyword);
        wrapEndPara();
    }
}
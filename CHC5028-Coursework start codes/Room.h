#ifndef TEXTADV_ROOM_H
#define TEXTADV_ROOM_H

#include <string>
#include <list>
#include "GameObject.h"
#include "EnemyObject.h"

class Room {
    std::string name;
    std::string description;
    Room* north;
    Room* east;
    Room* south;
    Room* west;
    std::list<GameObject*> objects;
    std::list<EnemyObject*> enemies;
public:
    Room(const std::string& _name, const std::string& _desc);
    ~Room();
    void describe() const;
    static std::list<Room*> rooms;
    static Room* addRoom(const std::string& _name, const std::string& _desc);
    static void addRoom(Room* room);
    Room* getNorth() const;
    void setNorth(Room* _north);
    Room* getEast() const;
    void setEast(Room* _east);
    Room* getSouth() const;
    void setSouth(Room* _south);
    Room* getWest() const;
    void setWest(Room* _west);
    void addObject(GameObject* obj);
    GameObject* getObject(const std::string& keyword);
    void removeObject(GameObject* obj);
    void addEnemy(EnemyObject* enemy);
    EnemyObject* getEnemy(const std::string& keyword);
    void removeEnemy(EnemyObject* enemy);
    void describeObjects() const;
};

#endif //TEXTADV_ROOM_H
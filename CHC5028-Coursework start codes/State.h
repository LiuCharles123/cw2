#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H

#include "Room.h"
#include <list>
#include <string>

class State {
    Room* currentRoom;
    int strength; // Player's physical strength
    std::list<GameObject*> inventory;
public:
    explicit State(Room* startRoom);
    ~State();
    void goTo(Room* target);
    void announceLoc() const;
    Room* getCurrentRoom() const;
    void reduceStrength(int amount);
    int getStrength() const;
    void addInventory(GameObject* obj);
    GameObject* getInventoryItem(const std::string& keyword);
    void removeInventoryItem(GameObject* obj);
    void describeInventory() const;
    void save(const std::string& filename) const;
    static State load(const std::string& filename, Room* startRoom);
};

#endif //TEXTADV_STATE_H
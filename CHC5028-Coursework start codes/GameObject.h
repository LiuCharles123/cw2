#ifndef TEXTADV_GAMEOBJECT_H
#define TEXTADV_GAMEOBJECT_H

#include <string>

class GameObject {
public:
    std::string keyword;
    float weight;
    GameObject(float w, const std::string& k) : weight(w), keyword(k) {}
    virtual ~GameObject() {}
    virtual std::string getType() const = 0;
};

#endif //TEXTADV_GAMEOBJECT_H
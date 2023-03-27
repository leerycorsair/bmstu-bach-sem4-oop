
#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <memory>
#include "objects/composite/composite.hpp"

class Scene
{
public:
    Scene();
    ~Scene() = default;
    void addObject(const std::shared_ptr<Object> &object);
    void removeObject(const Iterator &it);
    void accept(std::shared_ptr<Visitor> visitor);
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
    ConstIterator cbegin() const;
    ConstIterator cend() const;

private:
    std::shared_ptr<Object> objects;
};

#endif //__SCENE_HPP__

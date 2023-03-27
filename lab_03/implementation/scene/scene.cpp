#include "scene.hpp"

#include <utility>

Scene::Scene() : objects(std::make_shared<Composite>()) {}

void Scene::addObject(const std::shared_ptr<Object> &object)
{
    this->objects->add(object);
}

void Scene::removeObject(const Iterator &it)
{

    this->objects->remove(it);
}

Iterator Scene::begin()
{
    return this->objects->begin();
}

Iterator Scene::end()
{
    return this->objects->end();
}

void Scene::accept(std::shared_ptr<Visitor> visitor)
{
    this->objects->accept(std::move(visitor));
}

ConstIterator Scene::cbegin() const
{
    return this->objects->cbegin();
}

ConstIterator Scene::cend() const
{
    return this->objects->cend();
}

ConstIterator Scene::begin() const
{
    return this->objects->cbegin();
}

ConstIterator Scene::end() const
{
    return this->objects->cend();
}

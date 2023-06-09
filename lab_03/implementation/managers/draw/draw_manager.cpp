#include <utility>
#include <memory>

#include "draw_manager.hpp"
#include "scene/scene.hpp"
#include "visitor/draw_visitor/draw_visitor.hpp"

void DrawManager::setDrawer(std::shared_ptr<Drawer> drawer)
{
    this->drawer = std::move(drawer);
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera)
{
    this->camera = std::move(camera);
}

void DrawManager::draw(const std::shared_ptr<Scene> &scene)
{
    auto visitor = std::make_shared<DrawVisitor>(this->drawer, this->camera);
    scene->accept(visitor);
}

void DrawManagerCreator::createManager()
{
    static auto manager = std::make_shared<DrawManager>();
    this->manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager()
{
    if (this->manager == nullptr)
        this->createManager();

    return this->manager;
}
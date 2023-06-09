#include <managers/scene/scene_manager.hpp>
#include "add_model.hpp"

void AddModel::execute()
{
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}

AddModel::AddModel(std::shared_ptr<Object> model) : model(model) {}
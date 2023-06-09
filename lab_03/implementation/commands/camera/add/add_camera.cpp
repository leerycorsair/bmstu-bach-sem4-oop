#include <objects/model/model_details/point/point.hpp>
#include <objects/camera/camera.hpp>
#include <managers/scene/scene_manager.hpp>
#include "add_camera.hpp"

AddCamera::AddCamera(double x_pos, double y_pos, double z_pos) : x_pos(x_pos), y_pos(y_pos), z_pos(z_pos) {}

void AddCamera::execute()
{
    Point cam_pos(x_pos, y_pos, z_pos);

    auto camera = std::make_shared<Camera>();
    auto scene_manager = SceneManagerCreator().getManager();
    auto scene = scene_manager->getScene();

    camera->transform(cam_pos, cam_pos, cam_pos);
    scene->addObject(camera);
    scene_manager->setMainCamera(scene->end() - 1);
}

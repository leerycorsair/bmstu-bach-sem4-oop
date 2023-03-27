#ifndef __CONFIG_MANAGER_CREATOR_HPP__
#define __CONFIG_MANAGER_CREATOR_HPP__

#include <memory>
#include "../config_manager.hpp"

class ConfigManagerCreator
{
public:
    std::shared_ptr<ConfigManager> getManager();

private:
    void createManager();
    std::shared_ptr<ConfigManager> manager;
};

#endif //__CONFIG_MANAGER_CREATOR_HPP__

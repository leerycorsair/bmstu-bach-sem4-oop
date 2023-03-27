#ifndef __CONFIG_MANAGER_HPP__
#define __CONFIG_MANAGER_HPP__

#include <memory>
#include "solution/solution.hpp"
#include "registration/registration_maker.hpp"

class ConfigManager
{
public:
    ConfigManager();
    std::shared_ptr<ObjectLoaderCreator> getLoaderCreator(size_t id);

private:
    Solution solution;
};

#endif // __CONFIG_MANAGER_HPP__

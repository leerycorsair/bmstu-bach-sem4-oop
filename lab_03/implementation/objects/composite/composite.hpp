#ifndef __COMPOSITE_HPP__
#define __COMPOSITE_HPP__

#include "objects/object.hpp"

class Visitor;

class Composite : public Object
{
public:
    Composite() = default;
    explicit Composite(const std::shared_ptr<Object> &component);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);
    bool add(const std::shared_ptr<Object> &component) override;
    bool remove(const Iterator &iterator) override;
    Iterator begin() override;
    Iterator end() override;
    ConstIterator begin() const override;
    ConstIterator end() const override;
    ConstIterator cbegin() const override;
    ConstIterator cend() const override;
    bool is_visible() override;
    bool is_composite() const override;
    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    std::vector<std::shared_ptr<Object>> objects;
};

#endif //__COMPOSITE_HPP__

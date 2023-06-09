
#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include <memory>
#include <visitor/draw_visitor/draw_visitor.hpp>
#include "model_details/model_details.hpp"
#include "objects/object.hpp"

class Model : public VisibleObject
{
public:
    Model();
    explicit Model(std::shared_ptr<ModelDetails> details);
    Model(const Model &model);
    ~Model() override = default;
    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;
    void accept(std::shared_ptr<Visitor> visitor) override;
    friend void DrawVisitor::visit(const Model &model);

protected:
    const std::shared_ptr<ModelDetails> getDetails() const;

private:
    std::shared_ptr<ModelDetails> details;
};

#endif //__MODEL_HPP__

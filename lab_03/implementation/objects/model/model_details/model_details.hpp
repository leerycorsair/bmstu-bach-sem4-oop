#ifndef __MODEL_DETAILS_HPP__
#define __MODEL_DETAILS_HPP__

#include <vector>
#include "point/point.hpp"
#include "edge/edge.hpp"
#include "visitor/draw_visitor/draw_visitor.hpp"

class ModelDetails
{
public:
    friend class DrawVisitor;
    ModelDetails() = default;
    ModelDetails(std::vector<Point> &points, std::vector<Edge> &edges);
    ModelDetails(Point &center, std::vector<Point> &points, std::vector<Edge> &edges);
    ~ModelDetails() = default;
    void setCenter(const Point &point);
    void addPoint(const Point &point);
    void addEdge(const Edge &edge);
    const Point &getCenter() const;
    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params);

private:
    std::vector<Point> points;
    std::vector<Edge> edges;
    Point center{};
    void move(const Point &move_params);
    void scale(const Point &scale_params);
    void rotate(const Point &rotate_params);
    const std::vector<Point> &getPoints() const;
    const std::vector<Edge> &getEdges() const;
};

#endif //__MODEL_DETAILS_HPP__

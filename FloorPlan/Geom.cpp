#include "Geom.h"
#include "Ops.h"

Box::Box(point_t center, double width, double height) {
    initialize(center, width, height);
}

Box::Box(double x1, double y1, double x2, double y2) {
    initialize(point_t(x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2), x2 - x1, y2 - y1);
}

Box::Box(multi_polygon_t mpoly) {
    _poly = mpoly;
}

Box::Box(polygon_t poly) {
    multi_polygon_t _poly;
    _poly.push_back(poly);
}

const multi_polygon_t& Box::get_poly() const {
    return _poly;
}

double Box::area() const {
    return bg::area(_poly);
}

point_t Box::centroid() const {
    point_t centroid;
    bg::centroid(_poly, centroid);
    return centroid;
}

Box Box::operator+(const Box& other) const {
    return Box(poly_union(_poly, other._poly));
}

Box Box::operator-(const Box& other) const {
    return Box(poly_difference(_poly, other._poly));
}

Box Box::operator*(const Box& other) const {
    return Box(poly_intersection(_poly, other._poly));
}

void Box::initialize(point_t center, double width, double height) {
    polygon_t box_polygon;
}
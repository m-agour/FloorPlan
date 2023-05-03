#include "Room.h"
#include "Ops.h"
#include "Geom.h"

Room::Room(double center[2], double width, double height) {
    initialize(center, width, height);
}

Room::Room(double x1, double y1, double x2, double y2) {
    initialize({ x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2 }, x2 - x1, y2 - y1);
}

Room::Room(multi_polygon mpoly) {
    _poly = mpoly;
}

Room::Room(polygon poly) {

}

const multi_polygon& Room::get_poly() const {
    return _poly;
}

double Room::area() const {
    return bg::area(_poly);
}

const double center() const {
    return _center;
}


void Room::set_center(double x, double y) {
    _center[0] = x;
    _center[1] = y;
}

double Room::width() const {
	return _width;
}

double Room::height() const {
	return _height;
}

void Room::set_width(double width) {
	_width = width;
	initialize(_center, width, _height);
}

void Room::set_height(double height) {
	_height = height;
	initialize(_center, _width, height);
}

void Room::set_bounds(double x1, double y1, double x2, double y2) {
    initialize(x1, y1, x2, y2);
}

multi_polygon Room::operator+(const Room& other) const {
    return poly_union(_poly, other._poly);
}

multi_polygon Room::operator-(const Room& other) const {
    return poly_difference(_poly, other._poly);
}

multi_polygon Room::operator*(const Room& other) const {
    return poly_intersection(_poly, other._poly);
}

Room& Room::operator+=(const Room& other) {
    boost::geometry::union_(_poly, other._poly, _poly);
    return *this;
}

Room& Room::operator-=(const Room& other) {
    boost::geometry::difference(_poly, other._poly, _poly);
    return *this;
}

Room& Room::operator*=(const Room& other) {
    boost::geometry::intersection(_poly, other._poly, _poly);
    return *this;
}


void Room::initialize(double center[2], double width, double height) {
    _width = width;
    _height = height;
    _center[0] = center[0];
    _center[1] = center[1];
    _bounds[0] = center[0] - width / 2;
    _bounds[1] = center[1] - height / 2;
    _bounds[2] = center[0] + width / 2;
    _bounds[3] = center[1] + height / 2;
    initialize_poly(_bounds[0], _bounds[1], _bounds[2], _bounds[3]);
}

void Room::initialize(double x1, double y1, double x2, double y2) {
	_width = x2 - x1;
    _height = y2 - y1;
    _center[0] = x1 + _width / 2;
    _center[0] = y1 + _height / 2;
    _bounds[0] = x1;
    _bounds[1] = y1;
    _bounds[2] = x2;
    _bounds[3] = y2;
    initialize_poly(x1, y1, x2, y2);
}

void Room::initialize_poly(double x1, double y1, double x2, double y2) {
    _poly = getBox(x1, x2, y1, y2);
}
#pragma once
#include "Types.h"

class Box {
public:
    // Constructors
    Box(point_t center, double width, double height);
    Box(double x1, double y1, double x2, double y2);
    Box(multi_polygon_t mpoly);
    Box(polygon_t poly);

    // Getters
    const multi_polygon_t& get_poly() const;
    double area() const;
    point_t centroid() const;

    // Operators
    Box operator+(const Box& other) const;
    Box operator-(const Box& other) const;
    Box operator*(const Box& other) const;

private:
    multi_polygon_t _poly;
    void initialize(point_t center, double width, double height);
};


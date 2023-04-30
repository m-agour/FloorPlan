#include <iostream>
#include <boost/geometry/algorithms/intersection.hpp>
#include "Geom.h"
#include "Ops.h"
#include "Room.h"

int main() {
    auto b1 = Box(0, 0, 2, 2);
    auto b2 = Box(point_t(0, 0), 2, 2);


    multi_polygon_t uni = poly_union(b1, b2);
    multi_polygon_t inter = poly_intersection(b1, b2);


    auto room = Room(point_t(1, 1), 2, 2);


    std::cout << room << std::endl;
    std::cout << room.centroid().x() << ", " << room.centroid().y() << std::endl; 
    std::cout << room.area() << std::endl;

    return 0;
}

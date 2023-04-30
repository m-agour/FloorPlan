#include <iostream>
#include <boost/geometry/algorithms/intersection.hpp>
#include "Geom.h"
#include "Ops.h"

int main() {
    auto b1 = Box(0, 0, 5, 5);
    auto b2 = Box(point_t(0, 0), 5, 5);


    polygon_t intersection = poly_union(b1, b2);

    if (!intersection.outer().empty()) {
        std::cout << "Intersection: " << boost::geometry::wkt(intersection) << std::endl;
    }
    else {
        std::cout << "No intersection" << std::endl;
    }

    return 0;
}

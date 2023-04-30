#include <iostream>
#include <boost/geometry/algorithms/intersection.hpp>
#include "Geom.h"
#include "Ops.h"

int main() {
    auto b1 = Box(0, 0, 2, 2);
    auto b2 = Box(point_t(0, 0), 2, 2);


    multi_polygon_t uni = poly_union(b1, b2);
    multi_polygon_t inter = poly_intersection(b1, b2);

	std::cout << boost::geometry::wkt(get_centroid(uni)) << std::endl;
    std::cout << get_area(inter) << std::endl;



    return 0;
}

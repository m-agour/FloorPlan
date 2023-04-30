#include "Types.h"

multi_polygon_t poly_union(const polygon_t& poly1, const polygon_t& poly2);
multi_polygon_t poly_intersection(const polygon_t& poly1, const polygon_t& poly2);
multi_polygon_t poly_difference(const polygon_t& poly1, const polygon_t& poly2);
multi_polygon_t poly_union(const multi_polygon_t& poly1, const multi_polygon_t& poly2);
multi_polygon_t poly_intersection(const multi_polygon_t& poly1, const multi_polygon_t& poly2);
multi_polygon_t poly_difference(const multi_polygon_t& poly1, const multi_polygon_t& poly2);
point_t poly_centroid(const multi_polygon_t& mp);
double poly_area(const multi_polygon_t& mp);

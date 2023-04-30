#include "Types.h"


multi_polygon_t poly_union(const polygon_t& poly1, const polygon_t& poly2) {
    multi_polygon_t output;
    boost::geometry::union_(poly1, poly2, output);
    return output.empty() ? multi_polygon_t{polygon_t()} : output;
}

multi_polygon_t poly_intersection(const polygon_t& poly1, const polygon_t& poly2) {
    multi_polygon_t output;
    boost::geometry::intersection(poly1, poly2, output);
    return output.empty() ? multi_polygon_t{polygon_t()} : output;
}

multi_polygon_t poly_difference(const polygon_t& poly1, const polygon_t& poly2) {
	multi_polygon_t output;
	boost::geometry::difference(poly1, poly2, output);
	return output.empty() ? multi_polygon_t{polygon_t()} : output;
}

double get_area(const multi_polygon_t & mp) {
    return bg::area(mp);
}

point_t get_centroid(const multi_polygon_t& mp) {
	point_t centroid;
	bg::centroid(mp, centroid);
	return centroid;
}

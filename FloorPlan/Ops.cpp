#include "Types.h"

polygon_t poly_intersection(const polygon_t& poly1, const polygon_t& poly2) {
    std::vector<polygon_t> output;
    boost::geometry::intersection(poly1, poly2, output);
    return output.empty() ? polygon_t() : output.front();
}

polygon_t poly_union(const polygon_t& poly1, const polygon_t& poly2) {
	std::vector<polygon_t> output;
	boost::geometry::union_(poly1, poly2, output);
	return output.empty() ? polygon_t() : output.front();
}
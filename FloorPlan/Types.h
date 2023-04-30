#include <boost/geometry.hpp>

namespace bg = boost::geometry;

typedef bg::model::d2::point_xy<double> point_t;
typedef bg::model::polygon<point_t> polygon_t; 
typedef bg::model::box<point_t> box_t;

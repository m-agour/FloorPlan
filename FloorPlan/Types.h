#include <boost/geometry.hpp>
#include <boost/geometry/geometries/multi_polygon.hpp>

namespace bg = boost::geometry;

typedef bg::model::d2::point_xy<double> point_t;
typedef bg::model::polygon<point_t> polygon_t; 
typedef bg::model::box<point_t> box_t;
typedef boost::geometry::model::multi_polygon<polygon_t> multi_polygon_t;

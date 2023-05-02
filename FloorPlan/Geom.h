
#include <vector>
#include <geos/geom/GeometryFactory.h>


const geos::geom::GeometryFactory* geomFactory;

geos::geom::MultiPolygon* getMultiPolygon(const std::vector<std::vector<geos::geom::Coordinate>>& polygonsCoords);

geos::geom::MultiPolygon* get_Box(double x1, double x2, double y1, double y2);

geos::geom::MultiPolygon* getPolygon(const std::vector<geos::geom::Coordinate>& coords);

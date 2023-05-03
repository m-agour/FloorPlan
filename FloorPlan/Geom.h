
#include <vector>
#include <geos/geom/GeometryFactory.h>


const geos::geom::GeometryFactory* geomFactory;

geos::geom::Polygon* createPolygon(const std::vector<std::vector<geos::geom::Coordinate>>& polygonsCoords);

geos::geom::MultiPolygon* getBox(double x1, double x2, double y1, double y2);

geos::geom::MultiPolygon* createMultiPolygon(const std::vector<geos::geom::Coordinate>& coords);

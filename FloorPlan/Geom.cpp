#include "Ops.h"
#include "Types.h"

const geos::geom::GeometryFactory* geomFactory = geos::geom::GeometryFactory::getDefaultInstance();


geos::geom::Polygon* createPolygon(const std::vector<geos::geom::Coordinate>& coords) {
    auto coordSeq = new geos::geom::CoordinateArraySequence();
    for (const auto& coord : coords) {
        coordSeq->add(coord);
    }
    auto linearRing = geomFactory->createLinearRing(coordSeq);
    return geomFactory->createPolygon(linearRing, nullptr);
}

geos::geom::MultiPolygon* createMultiPolygon(const std::vector<std::vector<geos::geom::Coordinate>>& polygonsCoords) {
    std::vector<geos::geom::Geometry*>* polygons = new std::vector<geos::geom::Geometry*>();
    for (const auto& coords : polygonsCoords) {
        polygons->push_back(createPolygon(coords));
    }
    return geomFactory->createMultiPolygon(polygons);
}


geos::geom::MultiPolygon* getBox(double x1, double x2, double y1, double y2) {
    auto coordSeq = new geos::geom::CoordinateArraySequence();
    coordSeq->add(geos::geom::Coordinate(x1, y1));
    coordSeq->add(geos::geom::Coordinate(x1, y2));
    coordSeq->add(geos::geom::Coordinate(x2, y2));
    coordSeq->add(geos::geom::Coordinate(x2, y1));
    coordSeq->add(geos::geom::Coordinate(x1, y1));

    auto linearRing = geomFactory->createLinearRing(coordSeq);
    auto boundingBoxPolygon = geomFactory->createPolygon(linearRing, nullptr);

    auto polygons = new std::vector<geos::geom::Geometry*>({ boundingBoxPolygon });
    return geomFactory->createMultiPolygon(polygons);
}

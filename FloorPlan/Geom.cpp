#include <iostream>
#include "Types.h"

polygon_t Box(double x1, double y1, double x2, double y2) {

    polygon_t box_polygon;

    boost::geometry::append(box_polygon.outer(), point_t(x1, y1));
    boost::geometry::append(box_polygon.outer(), point_t(x1, y2));
    boost::geometry::append(box_polygon.outer(), point_t(x2, y2));
    boost::geometry::append(box_polygon.outer(), point_t(x2, y1));
    boost::geometry::append(box_polygon.outer(), point_t(x1, y1));


    return box_polygon;
}

polygon_t Box(point_t center, double width, double height) {

    polygon_t box_polygon;

    double x1 = center.x() - width / 2;
    double y1 = center.y() - height / 2;
    double x2 = center.x() + width / 2;
    double y2 = center.y() + height / 2;

    boost::geometry::append(box_polygon.outer(), point_t(x1, y1));
    boost::geometry::append(box_polygon.outer(), point_t(x1, y2));
    boost::geometry::append(box_polygon.outer(), point_t(x2, y2));
    boost::geometry::append(box_polygon.outer(), point_t(x2, y1));
    boost::geometry::append(box_polygon.outer(), point_t(x1, y1));


    return box_polygon;
}
#include "Geom.h"
#include "Types.h"


class Room {
public:
    Room(point_t center, double width, double height) : _poly(Box(center, width, height)) {}

    // Getters
    const polygon_t& get_poly() const {
        return _poly;
    }

    point_t centroid() const {
        point_t centroid(-1000, -1000);
        bg::centroid(_poly, centroid);
        return centroid;
    }

    double area() const {
        return bg::area(_poly);
    }


private:
    polygon_t _poly;

    friend std::ostream& operator<<(std::ostream& os, const Room& room) {
		os << boost::geometry::wkt(room._poly);
		return os;
	}
};
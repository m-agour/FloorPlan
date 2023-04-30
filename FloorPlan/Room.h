#include "Types.h"
#include "vector"

class Room {
public:
    Room(point_t center, double width, double height);
    Room(double x1, double y1, double x2, double y2);
    Room(multi_polygon_t mpoly);
    Room(polygon_t poly);

    const multi_polygon_t& get_poly() const;
    double area() const;
    double width() const;
    double height() const;
    point_t center() const;
    std::vector<double> bounds() const;


    void set_poly(multi_polygon_t mpoly);
    void set_poly(polygon_t poly);
    void set_width(double width);
    void set_height(double height);
    void set_center(point_t center);
    void set_center(double x, double y);
    void set_bounds(double x1, double y1, double x2, double y2);

    multi_polygon_t operator+(const Room& other) const;
    multi_polygon_t operator-(const Room& other) const;
    multi_polygon_t operator*(const Room& other) const;

    Room& operator+=(const Room& other);
    Room& operator-=(const Room& other);
    Room& operator*=(const Room& other);

private:
    multi_polygon_t _poly;
    double _width;
    double _height;
    point_t _center;
    double _bounds[4];

    void initialize(point_t center, double width, double height);
    void initialize(double x1, double y1, double x2, double y2);
    void initialize_poly(double x1, double y1, double x2, double y2);
};

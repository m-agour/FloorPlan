#include "Types.h"
#include "vector"

class Room {
public:
    Room(double center[2], double width, double height);
    Room(double x1, double y1, double x2, double y2);
    Room(multi_polygon mpoly);
    Room(polygon poly);

    const multi_polygon& get_poly() const;
    double area() const;
    double width() const;
    double height() const;
    double* center() const;
    double* bounds() const;


    void set_poly(multi_polygon mpoly);
    void set_poly(polygon poly);
    void set_width(double width);
    void set_height(double height);
    void set_center(double center[2]);
    void set_center(double x, double y);
    void set_bounds(double x1, double y1, double x2, double y2);

    multi_polygon operator+(const Room& other) const;
    multi_polygon operator-(const Room& other) const;
    multi_polygon operator*(const Room& other) const;

    Room& operator+=(const Room& other);
    Room& operator-=(const Room& other);
    Room& operator*=(const Room& other);

private:
    multi_polygon _poly;
    double _width;
    double _height;
    double _center[2];
    double _bounds[4];

    void initialize(double center[2], double width, double height);
    void initialize(double x1, double y1, double x2, double y2);
    void initialize_poly(double x1, double y1, double x2, double y2);
};

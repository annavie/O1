
// Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

class Point {
public:
    int x;
    int y;

    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    Point(const Point& other) : x(other.x), y(other.y) {}

    // Copy assignment operator
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
};



class Size {
public:
    int width;
    int height;

    Size(int w = 0, int h = 0) : width(w), height(h) {}

    Size(const Size& other) : width(other.width), height(other.height) {}

    Size& operator=(const Size& other) {
        if (this != &other) {
            width = other.width;
            height = other.height;
        }
        return *this;
    }
};

#endif // POINT_HPP

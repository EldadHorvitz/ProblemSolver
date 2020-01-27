//
// Created by nizan on 23/01/2020.
//

#include "Point.h"

Point::Point(int x1, int y1) : x(x1), y(y1) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

bool Point::equals(Point p1) {
    return (p1.getX() == this->x && p1.getY() == this->getY());
}

bool Point::operator==(Point p1) {
    return (p1.getX() == this->x && p1.getY() == this->getY());
}
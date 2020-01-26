//
// Created by nizan on 23/01/2020.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H


class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);

    bool equals(Point p1);
    bool operator==(Point p1);
    int getX() const;

    int getY() const;



};


#endif //EX4_POINT_H

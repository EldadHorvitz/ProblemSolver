//
// Created by nizan on 23/01/2020.
//

#ifndef EX4_PROBLEM_H
#define EX4_PROBLEM_H

#include "vector"
#include "Searchable.h"
#include "Point.h"

using namespace std;

class Problem : public Searchable<Point> {
public:

    Problem();

    Problem(const Point &start, const Point &end);

    void insertLine(string str);

    void setStart(const Point &start);

    void setEnd(const Point &end);

    const Point &getStart() const;

    const Point &getEnd() const;
    void insertEndPoint(string str);

    void insertStartPoint(string str);

private:
    Point start = Point(0, 0);
    Point end = Point(0, 0);
    vector<vector<double >> matrix;


};


#endif //EX4_PROBLEM_H

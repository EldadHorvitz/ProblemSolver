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
    Problem(int start, int end);

    int getStart() const;

    int getEnd() const;

private:
    int start;
    int end;
    vector<vector<double >>;

};


#endif //EX4_PROBLEM_H

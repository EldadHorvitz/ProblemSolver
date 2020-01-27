//
// Created by nizan on 23/01/2020.
//

#ifndef EX4_PROBLEM_H
#define EX4_PROBLEM_H

#include "vector"
#include "Searchable.h"
#include "Point.h"
#include "State.h"

using namespace std;
static int probCounter=0;
class Problem : public Searchable<Point> {

public:

    Problem();

    void insertLine(string str);

    string toString();
    void insertEndPoint(string str);

    void insertStartPoint(string str);

    void insertToState();

    State<Point > *getInit() override;

    State<Point > *getGoal() override;


    State<Point > *locateState(Point p);

    list<State<Point> *> getNeighbours(State<Point> *s) override;



private:
    int name;
    State<Point > *start;
    State<Point > *end;
    vector<vector<double >> matrix;
    int rowSize = this->matrix.size();;
    int colSize;
    list<State<Point > *> matrixStates;

};


#endif //EX4_PROBLEM_H

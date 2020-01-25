//
// Created by nizan on 23/01/2020.
//

#include <string>
#include <iostream>
#include <algorithm>
#include "Problem.h"

Problem::Problem() {}


void Problem::insertLine(string str) {
    std::string delimiter = ",";
    size_t pos = 0;
    vector<double> smallVector;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        double d = (stod(str.substr(0, pos)));
        smallVector.push_back(d);
        str.erase(0, pos + delimiter.length());
    }
    double d = (stod(str.substr(0, pos)));
    smallVector.push_back(d);
    this->matrix.push_back(smallVector);
}

void Problem::insertToState() {
    this->rowSize = this->matrix.size();
    int maxColSize = 0;
    int i = 0;
    for (i = 0; i < this->matrix.size(); i++) {
        if (this->matrix[i].size() > maxColSize) {
            maxColSize = this->matrix[i].size();
        }
    }
    this->colSize = maxColSize;
    int j;
    for (i = 0; i < this->rowSize; i++) {
        for (j = 0; j < this->colSize; j++) {
            Point p =  Point(i, j);
            double value = this->matrix[i][j];
            State<Point > *o = new State<Point >(p, value);
            this->matrixStates.push_back(o);
        }
    }
}


void Problem::insertStartPoint(string str) {
    std::string delimiter = ",";
    size_t pos = 0;
    int p1;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        p1 = (stoi(str.substr(0, pos)));
        str.erase(0, pos + delimiter.length());
    }
    int p2 = (stoi(str.substr(0, pos)));
    Point *p = new Point(p1, p2);
    double value = this->matrix[p1][p2];
    State<Point *> *o = new State<Point *>(p, value);
    this->start = o;
}

void Problem::insertEndPoint(string str) {
    std::string delimiter = ",";
    size_t pos = 0;
    int p1;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        p1 = (stoi(str.substr(0, pos)));
        str.erase(0, pos + delimiter.length());
    }
    int p2 = (stoi(str.substr(0, pos)));
    Point *p = new Point(p1, p2);
    double value = this->matrix[p1][p2];
    State<Point *> *o = new State<Point *>(p, value);
    this->end = o;
}


State<Point *> *Problem::getInit() {
    return this->start;
}

State<Point *> *Problem::getGoal() {
    return this->end;
}

list<State<Point *> *> Problem::getNeighbours(State<Point> p) {
    list<State<Point *> *> listN;
    int x1 = p.getState().getX();
    int y1 = p.getState().getY();
    //x+1,y
    if (!(x1 + 1 > this->rowSize)) {
        State<Point *> *g = this->locateState(new Point(x1, y1));
        listN.push_back(g);
    }
    //x,y+1
    if (!(y1 + 1 > this->colSize)) {
        State<Point *> *g = this->locateState(new Point(x1, y1 + 1));
        listN.push_back(g);
    }
    //x-1,y
    if (!(x1 - 1 < 0)) {
        State<Point *> *g = this->locateState(new Point(x1 - 1, y1));
        listN.push_back(g);
    }
    //x,y-1
    if (!(y1 - 1 < 0)) {
        State<Point *> *g = this->locateState(new Point(x1, y1 - 1));
        listN.push_back(g);
    }
    return listN;

}

State<Point *> *Problem::locateState(Point *p) {
    for (State<Point *> *c:this->matrixStates) {
        if (c->getState()->equals(p)) {
            return c;
        }
    }
}


//
// Created by nizan on 23/01/2020.
//

#include <string>
#include <iostream>
#include <algorithm>
#include "Problem.h"

Problem::Problem() {}


const Point &Problem::getStart() const {
    return start;
}

const Point &Problem::getEnd() const {
    return end;
}


void Problem::setStart(const Point &start) {
    Problem::start = start;
}

void Problem::setEnd(const Point &end) {
    Problem::end = end;
}

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

void Problem::insertStartPoint(string str) {
    std::string delimiter = ",";
    size_t pos = 0;
    int p1;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        p1 = (stoi(str.substr(0, pos)));
        str.erase(0, pos + delimiter.length());
    }
    int p2 = (stoi(str.substr(0, pos)));
    this->setStart(Point(p1, p2));
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
    this->setEnd(Point(p1, p2));
}

list<Point> Problem::neighbors(Point p) {
    list<Point> listN;
    this->rowSize = this->matrix.size();
    int maxColSize = 0;
    int i = 0;
    for (i = 0; i < this->matrix.size(); i +=) {
        if (this->matrix[i].size() > maxColSize) {
            maxColSize = this->matrix[i].size();
        }
    }
    this->colSize = maxColSize;

    int x1 = p.getX();
    int y1 = p.getY();

    //x+1,y
    if (!(x1 + 1 > this->rowSize)) {
        listN.push_back(Point(x1, y1));
    }
    //x,y+1
    if (!(y1 + 1 > this->colSize)) {
        listN.push_back(Point(x1, y1 + 1));
    }
    //x-1,y
    if (!(x1 - 1 < 0)) {
        listN.push_back(Point(x1 - 1, y1));
    }
    //x,y-1
    if (!(y1 - 1 < 0)) {
        listN.push_back(Point(x1, y1 - 1));
    }

    return listN;
}

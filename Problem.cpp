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
    int i = 0;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        double d = (stod(str.substr(0, pos)));
        str.erase(0, pos + delimiter.length());
        i++;
    }
}

void Problem::insertStartPoint(string str) {
    std::string delimiter = ",";
    size_t pos = 0;
    int p1 = (stoi(str.substr(0, pos)));
    str.erase(0, pos + delimiter.length());
    int p2 = (stoi(str.substr(0, pos)));
    this->setStart(Point(p1, p2));
}

void Problem::insertEndPoint(string str) {
    std::string delimiter = ",";
    size_t pos = 0;
    int p1 = (stoi(str.substr(0, pos)));
    str.erase(0, pos + delimiter.length());
    int p2 = (stoi(str.substr(0, pos)));
    this->setEnd(Point(p1, p2));
}
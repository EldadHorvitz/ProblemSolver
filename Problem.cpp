//
// Created by nizan on 23/01/2020.
//

#include "Problem.h"

Problem::Problem(int start, int end) : start(start), end(end) {}

int Problem::getStart() const {
    return start;
}

int Problem::getEnd() const {
    return end;
}

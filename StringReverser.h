//
// Created by nizan on 22/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H


#include <string>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string);

};


#endif //EX4_STRINGREVERSER_H

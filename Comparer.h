//
// Created by eldad on 26/01/2020.
//

#ifndef EX4_COMPARER_H
#define EX4_COMPARER_H

#include "State.h"
#include "Point.h"
class Comparer {
public:
    bool operator()(State<Point> *s1,State<Point>* s2){
        return (s1->getCostSum()>s2->getCostSum());
    }
};


#endif //EX4_COMPARER_H

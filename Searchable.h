//
// Created by nizan on 22/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "State.h"
#include <list>
#include "Point.h"

template<class T>
class Searchable {

public:
    virtual State<T> *getInit() = 0;

    virtual State<T> *getGoal() = 0;

    virtual std::list<State<T> *> getNeighbours(State<T> *s) = 0;

    virtual ~Searchable() {

    }
};


#endif //EX4_SEARCHABLE_H

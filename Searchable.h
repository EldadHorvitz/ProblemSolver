//
// Created by nizan on 22/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "State.h"
#include <list>
template <class T>
class Searchable {

public:
    State<T> *getInit();
    State<T> *getGoal();
    std::list<State<T>*> getNeighbours(State<T> s);
};


#endif //EX4_SEARCHABLE_H

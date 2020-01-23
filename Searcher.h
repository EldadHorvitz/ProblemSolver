//
// Created by nizan on 22/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"

template<class T,class S>

class Searcher {
public:
    virtual S search(Searchable<T> s) = 0;
    //returns how many states we passed until we reached the solution
    virtual int getNumLength()=0;


};


#endif //EX4_SEARCHER_H

//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include "Searcher.h"
template<class T,class S>
class AStar: public Searcher<T,S> {
private: int counter;
public:

    int getNumLength();
    S search(Searchable<T> s);



};




#endif //EX4_ASTAR_H

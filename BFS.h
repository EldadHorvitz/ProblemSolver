//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include "Searcher.h"
template<class T,class S>
class BFS: public Searcher<T,S> {

private:
    int counter=0;
public:

    int getNumLength();
    S search(Searchable<T> s);



};







#endif //EX4_BFS_H

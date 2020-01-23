//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
template<class T,class S>
class DFS: public Searcher<T,S> {

private:
    int counter=0;
public:

    int getNumLength();
    S search(Searchable<T> s);



};






#endif //EX4_DFS_H

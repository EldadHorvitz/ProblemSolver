//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_BSTFS_H
#define EX4_BSTFS_H


#include "Searcher.h"
template<class T,class S>
class BstFS: public Searcher<T,S> {
private: int counter;
public:
    BstFS();
    int getNumLength();
    S search(Searchable<T> s);

    virtual ~BstFS();

};

template<class T, class S>
BstFS<T, S>::BstFS():counter(0) {}

template<class T, class S>
BstFS<T, S>::~BstFS() {

}


#endif //EX4_BSTFS_H

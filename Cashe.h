//
// Created by eldad on 24/01/2020.
//

#ifndef EX4_CASHE_H
#define EX4_CASHE_H



using namespace std;

#include <map>
#include <list>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>
#include "Problem.h"
#include "Point.h"

template <class P,class S>
class Cashe {
private:
    map<P, S> *myMap;
    list<P> *myList;
    unsigned int size;
    unsigned int counter;
public:
    virtual bool count(P key) = 0;
    virtual void insert(P key, S obj) = 0;
    virtual S get(P key) = 0;


};




#endif //EX4_CASHE_H

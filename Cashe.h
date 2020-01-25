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
    virtual ~Cashe();
    Cashe();
    bool count(P key);
    void insert(P key, S obj);
    S get(P key);


};




#endif //EX4_CASHE_H

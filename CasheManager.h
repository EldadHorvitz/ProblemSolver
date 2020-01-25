//
// Created by eldad on 13/01/2020.
//

#ifndef EX4_CASHEMANAGER_H
#define EX4_CASHEMANAGER_H

#include <map>
#include <list>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>
#include "Problem.h"
#include "Point.h"

using namespace std;

template<class P, class S>
class CasheManager {
private:
    map<P, S> *myMap;
    list<P> *myList;
    unsigned int size;
    unsigned int counter;
public:
    virtual ~CasheManager();

    CasheManager() {}


    bool count(P key);

    void insert(P key, S obj);

    S get(P key);


};


#endif //EX4_CASHEMANAGER_H

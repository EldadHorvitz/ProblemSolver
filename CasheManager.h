//
// Created by eldad on 13/01/2020.
//

#ifndef EX4_CASHEMANAGER_H
#define EX4_CASHEMANAGER_H
using namespace std;

#include <map>
#include <list>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>
#include "Problem.h"
#include "Point.h"

template<class P, class S>
class CasheManager {
private:
    map<P, S> *myMap;
    list <P> *myList;
    unsigned int size;
    unsigned int counter;

public:
    //
// Created by eldad on 13/01/2020.
//


    S get(P key) {
        if (this->myMap->count(key)) {
            myList->remove(key);
            myList->push_front(key);
            return (*myMap)[key];
        } else {
            ifstream read_file;
            read_file.open(key.toString() + ".txt");
            if (!read_file) {
                throw "file wasn't found";
            } else {
                S newObj;
                string STxt = "", temp = "";
                while (!read_file.eof()) // To get you all the lines.
                {
                    getline(read_file, temp); // Saves the line in STRING.
                    STxt += temp;
                }
                newObj = new S(STxt);
                myMap->erase(myList->back());
                myList->pop_back();
                myMap->insert({key, newObj});
                myList->push_front(key);
                return newObj;
            }
        }

    }

    bool count(P key) {
        if (this->myMap->count(key)) {
            return true;
        } else {
            ifstream read_file(key.toString() + ".txt");
            if (read_file) {
                return true;
            }
            return false;
        }

    }

    void insert(P key, S obj) {
        if (this->myMap.count(key)) {
            *myMap[key] = obj;
            myList->remove(key);
            myList->push_front(key);
        } else {
            // didn't reach the maximum size yet
            if (counter < size) {
                myMap->insert({key, obj});
                counter++;
                myList->push_front(key);
            } else {
                myMap->erase(myList->back());
                myList->pop_back();
                myMap->insert({key, obj});
                myList->push_front(key);
            }

        }
        ofstream out_file;
        out_file.open(key.toString() + ".txt");
        if (!out_file) {
            throw "file isn't open";
        } else {
            out_file << obj.toString();
            out_file.close();
        }


    }


    ~CasheManager() {

    }


    CasheManager() : myMap(new map<P, S>()), myList(new list<P>()), size(5), counter(0) {}


};


#endif //EX4_CASHEMANAGER_H

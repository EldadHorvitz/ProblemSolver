//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_OA_H
#define EX4_OA_H
using namespace std;

#include <string>
#include "Solver.h"
#include "Searcher.h"
#include "Point.h"
#include "BFS.h"
#include "DFS.h"
#include "BstFS.h"
#include "AStar.h"

template<class P, class S>
class OA : public Solver<P, S> {
private:

public:
    OA() {

    }

    S solve(P *p) {
        __attribute__((unused))   Searcher<Point, string> *BFS1 = new BFS<Point, string>();
        __attribute__((unused))  Searcher<Point, string> *DFS1 = new DFS<Point, string>();
        __attribute__((unused))  Searcher<Point, string> *BstFS1 = new BstFS<Point, string>();
        __attribute__((unused))  Searcher<Point, string> *AStar1 = new AStar<Point, string>();
        //    string s1=BFS1->search(p)+"\n";
        //string s2=DFS1->search(p)+"\n";
        // string s3=BstFS1->search(p)+"\n";
        string s4 = AStar1->search(p) + "\n";
        return s4;
    }
};


#endif //EX4_OA_H

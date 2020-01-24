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

template <class P,class S>
class OA: public Solver<P,S>{
private:
    Searcher<Point*,string>* BFS1;
    Searcher<Point*,string>* DFS1;
    Searcher<Point*,string>* BstFS1;
    Searcher<Point*,string>* AStar1;
public:
    OA() {
        this->BFS1=new BFS<Point*,string>();
        this->DFS1=new DFS<Point*,string>();
        this->BstFS1=new BstFS<Point*,string>();
        this->AStar1=new AStar<Point*,string>();
    }

    S solve(P p) override;
};



#endif //EX4_OA_H

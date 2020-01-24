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
    Searcher<Point*,string>* BFS;
    Searcher<Point*,string>* DFS;
    Searcher<Point*,string>* BstFS;
    Searcher<Point*,string>* AStar;
public:
    OA() {
        this->BFS=new ::BFS<Point*,string>();
        this->DFS=new ::DFS<Point*,string>();
        this->BstFS=new ::BstFS<Point*,string>();
        this->AStar=new ::AStar<Point*,string>();
    }

    S solve(P p) override;
};



#endif //EX4_OA_H

//
// Created by eldad on 23/01/2020.
//

#include "OA.h"
template <class P,class S>
S OA<P,S>::solve(P p) {
    string s1=this->BFS->search(p);
    string s2=this->DFS->search(p);
    string s3=this->BstFS->search(p);
    string s4=this->AStar->search(p);
    return s4;

}
//
// Created by eldad on 23/01/2020.
//

#include "OA.h"
template <class P,class S>
S OA<P,S>::solve(P p) {
    string s1=this->BFS1->search(p);
    string s2=this->DFS1->search(p);
    string s3=this->BstFS1->search(p);
    string s4=this->AStar1->search(p);
    return s4;

}
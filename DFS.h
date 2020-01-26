//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
#include "Point.h"

using namespace std;
#include <stack>
#include <vector>
#include <list>
#include <string>
template<class T,class S>
class DFS: public Searcher<T,S> {

private:
    int counter;
public:

    DFS():counter(0) {}

    S search(Searchable<T>* s){
        stack <State<T>*> open;
        s->getInit()->setCostSum(1);
        open.push(s->getInit());
        while (!open.empty()){
            counter++;
            State<T> * n;
            n = open.top();
            open.pop();
            n->setVisited(true);
            if (n->getState()==s->getGoal()->getState()){
                return getSolution(n,s->getInit());
            }
            list<State<T>*> l=s->getNeighbours(n);
            for (State<T>* s1:l){
                if (!s1->isVisited()){
                    s1->setCostSum(1+n->getCostSum());
                    s1->setDad(n);
                    open.push(s1);
                }

            }
        }

    }
    int getNumLength(){
        return counter;
    }
    string getSolution(State<T> *goal,State<T> *origin) {
        string solution1 = "";
        vector < State<T>  > v;
        State<T> temp = *goal;
        int count = 0;
        while (!(temp.getState() == origin->getState())) {
            v.push_back(temp);
            temp = *(temp.getDad());
            count++;
        }
        v.push_back(temp);
        int i;
        State<T> cur=*goal;
        State<T> son=*goal;
        bool f = true;
        for (i = count; i > 0; --i) {
            cur = v[i];
            son = v[i - 1];
            if (!f) {
                solution1 += " ,";
            } else {
                f = false;
            }
            Point pCur = (Point ) cur.getState();
            Point pSon = (Point ) son.getState();
            if (pCur.getX() > pSon.getX()) {
                solution1 = solution1 + "Right (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getX() < pSon.getX()) {
                solution1 = solution1 + "Left (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getY() > pSon.getY()) {
                solution1 = solution1 + "Down (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getY() < pSon.getY()) {
                solution1 = solution1 + "Up (" + to_string(int(v[i - 1].getCostSum())) + ")";
            }
        }
        return solution1;
    }



};






#endif //EX4_DFS_H

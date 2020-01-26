//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include "Searcher.h"
#include "Point.h"

using namespace std;

#include <queue>
#include <list>
#include <string>

template<class T, class S>
class BFS : public Searcher<T, S> {

private:
    int counter;
public:

    BFS() : counter(0) {}

    S search(Searchable<T> *s) {
        State<T>* begin=s->getInit();
        State<T> erd=State<T>((Point) begin->getState(),begin->getCost());

        queue < State<T> * > open;
        begin->setCostSum(1);
        open.push(begin);
        begin->setVisited(true);
        while (!open.empty()) {
            counter++;
            State<T> *n;
            n = open.front();
            open.pop();
            n->setVisited(true);
            if (n->getState() == s->getGoal()->getState()) {
                cout<<counter<<endl;
                return getSolution(n, begin);
            }
            list<State<T> *> l = s->getNeighbours(n);
            for (State<T> *s1:l) {
                if (!s1->isVisited()&&!has(open,s1)) {
                    s1->setCostSum(1 + n->getCostSum());
                    s1->setDad(n);
                    open.push(s1);
                }

            }
        }

    }

    int getNumLength() {
        return counter;
    }

    string getSolution(State<T> *goal, State<T> *origin) {
        string solution1 = "";
        vector<State<T> > v;
        State<T> temp = *goal;
        int count = 0;
        Point tempp=(Point) temp.getState();
        Point originp=(Point)  origin->getState();
        while ((tempp.getX() != originp.getX() || (tempp.getY() != originp.getY()))) {
            v.push_back(temp);
            temp = *(temp.getDad());
            count++;
            tempp=(Point) temp.getState();
        }
        v.push_back(temp);
        int i;
        State<T> cur = *goal;
        State<T> son = *goal;
        bool f = true;
        for (i = count; i > 0; --i) {
            cur = v[i];
            son = v[i - 1];
            if (!f) {
                solution1 += " ,";
            } else {
                f = false;
            }
            Point pCur = (Point) cur.getState();
            Point pSon = (Point) son.getState();
            if (pCur.getX() > pSon.getX()) {
                solution1 = solution1 + "Up (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getX() < pSon.getX()) {
                solution1 = solution1 + "Down (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getY() > pSon.getY()) {
                solution1 = solution1 + "Left (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getY() < pSon.getY()) {
                solution1 = solution1 + "Right (" + to_string(int(v[i - 1].getCostSum())) + ")";
            }
        }
        return solution1;
    }
    bool has(queue<State<T> *> q, State<T> *s) {
        while (!q.empty()){
            State<T> *temp=q.front();
            if (temp->getState()==s->getState()){
                return true;
            }
            q.pop();
        }
        return false;
    }


};


#endif //EX4_BFS_H

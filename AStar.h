//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include "Point.h"


using namespace std;
#include <queue>
#include <list>
#include <string>
#include "Searcher.h"

template<class T, class S>
class AStar : public Searcher<T, S> {
private:
    int counter;
public:

    AStar():counter(0) {}

    S search(Searchable<T>* s) {
        queue < State<T> * > open;
        s->getInit()->setCostSum(s->getInit()->getCost());
        update(s->getInit(), s);
        open.push(s->getInit());
        queue < State<T> * > close;
        while (!open.empty()) {
            open = priority(open);
            counter++;
            State<T> *n = open.front();
            open.pop();
            update(n, s);
            close.push(n);
            if (n == s->getGoal()) {
                return getSolution(n, s->getInit());
            }
            list < State<T> * > l = s->getNeighbours(n);

            for (State<T> *s1:l) {
                update(s1, s);
                if ((!has(open, s1)) && (!has(close, s1))) {
                    s1->setCostSum(s1->getCost() + n->getCostSum());
                    s1->setDad(n);
                    open.push(s1);
                } else if (s1->getCostSum() > s1->getCost() + n->getCostSum()) {
                    s1->setCostSum(s1->getCost() + n->getCostSum());
                    s1->setDad(n);
                    if (!has(open, s1)) {
                        open.push(s1);
                    }

                }

            }
        }

    }

    bool has(queue<State<T> *> q, State<T> *s) {
        for (State<T> *s1:q) {
            if (s == s1) {
                return true;
            }
        }
        return false;
    }

    int getNumLength() {
        return counter;
    }


    queue<State<T> *> priority(queue<State<T> *> q) {
        queue < State<T> * > temp;
        State<T> *a = q.front();
        q.pop();
        State<T> *min = a;
        while (!q.empty()) {
            if ((min->getCostSum() + min->getUCostSum()) < (a->getCostSum() + a->getUCostSum())) {
                min = a;
            }
            temp.push(a);
            a = q.front();
            q.pop();
        }
        a = temp.front();
        temp.pop();
        q.push(min);
        while (!temp.empty()) {
            if (!(a == min)) {
                temp.push(a);
            }
            a = q.front();
            q.pop();
        }
        return q;
    }

    void update(State<T> *t, Searchable<T> *s) {
        Point cur = (Point ) t->getState();
        Point dst = (Point ) s->getGoal()->getState();
        double x = dst.getX() - cur.getX();
        if (x < 0) {
            x = x * (-1);
        }
        double y = dst.getY() - cur.getY();
        if (y < 0) {
            y = y * (-1);
        }
        double dist = x + y;
        t->setUCostSum(dist);
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
        State<T> cur;
        State<T> son;
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


#endif //EX4_ASTAR_H

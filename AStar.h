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
    class Cmp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getCostSum() + left->getUCostSum() > right->getCostSum() + right->getUCostSum());
        }
    };
private:
    int counter;
public:

    AStar() : counter(0) {}

    S search(Searchable<T> *s) {
        priority_queue <State<T>*,vector<State<T>*>,Cmp> open;
        s->getInit()->setCostSum(s->getInit()->getCost());
        update(s->getInit(), s);
        open.push(s->getInit());
        queue<State<T> *> close;
        while (!open.empty()) {
            State<T>* n = open.top();
            counter++;
            open.pop();
            update(n, s);
            close.push(n);
            if (n->getState() == s->getGoal()->getState()) {
                return getSolution(n, s->getInit());
            }
            list<State<T> *> l = s->getNeighbours(n);
            for (State<T> *s1:l) {
                double temp = n->getCostSum() + s1->getCost();
                if ((has2(close, s1)) || (temp >= s1->getCostSum() && s1->getCostSum() != 0)) {
                    continue;
                } else if (!has(open, s1) || temp < s1->getCostSum() || s1->getCostSum() == 0) {
                    s1->setCostSum(temp);
                    s1->setDad(n);
                    update(s1, s);
                    if (!has(open, s1)) {
                        open.push(s1);
                    }
                }
            }
        }
        return "error";
    }

    bool has(priority_queue <State<T>*,vector<State<T>*>,Cmp> q, State<T> *s) {
        while (!q.empty()){
            State<T> *temp=q.top();
            if (temp->getState()==s->getState()){
                return true;
            }
            q.pop();
        }
        return false;
    }
    bool has2(queue<State<T> *> q, State<T> *s) {
        while (!q.empty()) {
            State<T> *temp = q.front();
            if (temp->getState() == s->getState()) {
                return true;
            }
            q.pop();
        }
        return false;
    }

    int getNumLength() {
        return counter;
    }


    queue<State<T> *> priority(queue<State<T> *> q) {
        if (q.empty()){
            return q;
        }
        queue<State<T> *> temp;
        State<T> *a = q.front();
        q.pop();
        State<T> *min = a;
        temp.push(a);
        while (!q.empty()) {
            a = q.front();
            q.pop();
            if ((min->getCostSum() + min->getUCostSum()) > (a->getCostSum() + a->getUCostSum())) {
                min = a;
            }
            temp.push(a);
        }
        a = temp.front();
        temp.pop();
        q.push(min);
        while (!temp.empty()) {
            if (!(a->getState() == min->getState())) {
                q.push(a);
            }
            a = temp.front();
            temp.pop();
        }
        return q;
    }

    void update(State<T> *t, Searchable<T> *s) {
        Point cur = (Point) t->getState();
        Point dst = (Point) s->getGoal()->getState();
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

    string getSolution(State<T> *goal, State<T> *origin) {
        string solution1 = "";
        vector<State<T> > v;
        State<T> temp = *goal;
        int count = 0;
        while (!(temp.getState() == origin->getState())) {
            v.push_back(temp);
            temp = *(temp.getDad());
            count++;
        }
        this->counter=count;
        int a =this->counter;
        stringstream ss;
        ss << a;
        string str = ss.str();
        solution1+=str+":\n";

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

};


#endif //EX4_ASTAR_H

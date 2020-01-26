//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_BSTFS_H
#define EX4_BSTFS_H


#include "Searcher.h"
#include "Point.h"

using namespace std;
#include <queue>
#include <list>
#include <string>
template<class T,class S>
class BstFS: public Searcher<T,S> {

private:
    int counter;
public:
    virtual ~BstFS() {

    }

    BstFS() : counter(0) {}

    S search(Searchable<T>* s){
        queue <State<T>*> open;
        s->getInit()->setCostSum(s->getInit()->getCost());
        open.push(s->getInit());
        queue <State<T>*> close;
        while (!open.empty()){
            open=priority(open);
            counter++;
            State<T>* n=open.front();
            open.pop();
            close.push(n);
            if (n->getState()==s->getGoal()->getState()){
                return getSolution(n,s->getInit());
            }
            list<State<T>*> l=s->getNeighbours(n);
            for (State<T>* s1:l){
                if ((!has(open, s1))&&(!has(close, s1))){
                    s1->setCostSum(s1->getCost()+n->getCostSum());
                    s1->setDad(n);
                    open.push(s1);
                }else if(s1->getCostSum()>s1->getCost()+n->getCostSum()){
                    s1->setCostSum(s1->getCost()+n->getCostSum());
                    s1->setDad(n);
                    if(!has(open, s1)){
                        open.push(s1);
                    }

                }

            }
        }

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
    int getNumLength(){
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
            if (min->getCostSum()<a->getCostSum()){
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
        State<T> cur= *goal;
        State<T> son= *goal;
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
                solution1 = solution1 + "Left (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getX() < pSon.getX()) {
                solution1 = solution1 + "Right (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getY() > pSon.getY()) {
                solution1 = solution1 + "Up (" + to_string(int(v[i - 1].getCostSum())) + ")";
            } else if (pCur.getY() < pSon.getY()) {
                solution1 = solution1 + "Down (" + to_string(int(v[i - 1].getCostSum())) + ")";
            }
        }
        return solution1;
    }
};




#endif //EX4_BSTFS_H



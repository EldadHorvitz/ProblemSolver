//
// Created by eldad on 23/01/2020.
//

#include "BFS.h"
#include "Point.h"

using namespace std;
#include <queue>
#include <list>
#include <string>

template<class T, class S>
BFS<T, S>::BFS():counter(0) {}

template<class T,class S>
S BFS<T,S>::search(Searchable<T> s){
    queue <State<T>*> open;
    s.getInit().setCostSum(1);
    open.push(s.getInit());
    while (!open.empty()){
        counter++;
        State<T>* n=open.pop();
        n->setVisited(true);
        if (n==s.getGoal()){
            return getSolution(n,s.getInit());
        }
        list<State<T>*> l=s.getNeighbours(n);
        for (State<T>* s1:l){
            if (!s1->isVisited()){
                s1->setCostSum(1+n->getCostSum());
                s1->setDad(n);
                open.push(s1);
            }

        }
    }

}
template<class T,class S>
int BFS<T,S>::getNumLength(){
    return counter;
}
template<class T,class S>
string getSolution(State<T> *goal,State<T> *origin){
    string solution1= "";
    vector<State<T> *> v= new vector<State<T> *>();
    State<T> *temp=goal;
    int count=0;
    while (!(temp==origin)){
        v.insert(temp);
        temp=temp->getDad();
        count++;
    }
    v.insert(temp);
    int i;
    State<T> *cur;
    State<T> *son;
    bool f= true;
    for (i=count;i>0;--i){
        cur = v[i];
        son = v[i - 1];
        if (!f) {
            solution1 += " ,";
        } else {
            f = false;
        }
        Point* pCur= (Point*) cur->getState();
        Point* pSon= (Point*) cur->getState();
        if (pCur->getX()> pSon->getX()) {
            solution1 = solution1 + "Right (" + to_string(int(v[i - 1].getCostSum())) + ")";
        } else if (pCur->getX() < pSon->getX()) {
            solution1 = solution1 + "Left (" + to_string(int(v[i - 1].getCostSum())) + ")";
        } else if (pCur->getY() > pSon->getY()) {
            solution1 = solution1 + "Down (" + to_string(int(v[i - 1].getCostSum())) + ")";
        } else if (pCur->getY() < pSon->getY()) {
            solution1 = solution1 + "Up (" + to_string(int(v[i - 1].getCostSum())) + ")";
        }
    }
    return solution1;

}

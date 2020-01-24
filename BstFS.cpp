//
// Created by eldad on 23/01/2020.
//
using namespace std;
#include "BstFS.h"
#include "Point.h"
#include <queue>
#include <list>
#include <string>

template<class T,class S>
S BstFS<T,S>::search(Searchable<T> s){
    queue <State<T>*> open;
    s.getInit()->setCostSum(s.getInit()->getCost());
    open.push(s.getInit());
    queue <State<T>*> close;
    while (!open.empty()){
        open=priority(open);
        counter++;
        State<T>* n=open.pop();
        close.push(n);
        if (n==s.getGoal()){
            return getSolution(n,s.getInit());
        }
        list<State<T>*> l=s.getNeighbours(n);
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
template<class T,class S>
bool has (queue <State<T>*> q,State<T> *s){
    for (State<T>* s1:q){
        if (s==s1){
            return true;
        }
    }
    return false;
}
template<class T,class S>
int BstFS<T,S>::getNumLength(){
    return counter;
}
template<class T,class S>
queue <State<T>*> priority(queue <State<T>*> q){
    queue <State<T>*> temp;
    State<T>* a=q.pop();
    State<T>* min=a;
    while(!q.empty()){
        if (min->getCostSum()<a->getCostSum()){
            min=a;
        }
        temp.push(a);
        a=q.pop();
    }
    a=temp.pop();
    q.push(min);
    while(!temp.empty()){
        if (!(a==min)){
            temp.push(a);
        }
        a=q.pop();
    }
    return q;
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
        Point pCur= (Point) cur->getState();
        Point pSon= (Point) cur->getState();
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
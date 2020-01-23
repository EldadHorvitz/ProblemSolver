//
// Created by eldad on 23/01/2020.
//
using namespace std;
#include "BstFS.h"
#include <queue>
#include <list>
template<class T,class S>
S BstFS<T,S>::search(Searchable<T> s){
    priority_queue <State<T>*> open;
    s.getInit()->setCostSum(s.getInit()->getCost());
    open.push(s.getInit());
    queue <State<T>*> close;
    while (!open.empty()){
        counter++;
        State<T>* n=open.pop();
        close.push(n);
        if (n==s.getGoal()){
            return;//return path
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
                }else{
                    //priority
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
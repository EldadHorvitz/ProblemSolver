//
// Created by eldad on 23/01/2020.
//
using namespace std;
#include "BstFS.h"
#include <queue>
#include <list>
template<class T,class S>
S BstFS<T,S>::search(Searchable<T> s){
    priority_queue <State<T>> open;
    open.push(s.getInit());
    queue <State<T>> close;
    while (!open.empty()){
        counter++;
        State<T> n=open.pop();
        close.push(n);
        if (n==s.getGoal()){
            return;
        }
        list<State<T>> l=s.getNeighbours(n);
        for (State<T> s1:l){
            s1.setDad(n);
            s1.setCost(n.getCost()+s1.getCost());
            if ((!has(open, s1))&&(!has(close, s1))){
                open.push(s1);
            }
        }
    }

}
template<class T,class S>
bool has (queue <State<T>> q,State<T> s){
    for (State<T> s1:q){
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
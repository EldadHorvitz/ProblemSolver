//
// Created by eldad on 23/01/2020.
//

#include "BFS.h"
using namespace std;
#include <queue>
#include <list>
template<class T,class S>
S BFS<T,S>::search(Searchable<T> s){
    queue <State<T>> open;
    s.getInit().setCostSum(1);
    open.push(s.getInit());
    while (!open.empty()){
        counter++;
        State<T> n=open.pop();
        n.setVisited(true);
        if (n==s.getGoal()){
            return;//return path
        }
        list<State<T>> l=s.getNeighbours(n);
        for (State<T> s1:l){
            if (!s1.isVisited()){
                s1.setCostSum(1+n.getCostSum());
                s1.setDad(n);
                open.push(s1);
            }

        }
    }

}
template<class T,class S>
int BFS<T,S>::getNumLength(){
    return counter;
}
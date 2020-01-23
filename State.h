//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include "Point.h"

template<class T>
class State {
private:
    T state;
    double cost;
    double costSum;
    State<T> dad;
    bool visited;
public:
    virtual ~State() {

    }

    T getState() const {
        return state;
    }


    void setDad(const State<T> &dad) {
        State::dad = dad;
    }

    void setVisited(bool visited) {
        State::visited = visited;
    }

    double getCost() const {
        return cost;
    }

    const State<T> &getDad() const {
        return dad;
    }

    bool isVisited() const {
        return visited;
    }


    State(T state, double cost) : state(state), cost(cost), costSum(cost), visited(false) {}

    double getCostSum() const {
        return costSum;
    }

    void setCostSum(double costSum) {
        State::costSum = costSum;
    }


    bool equals(State<T> s) {
        state.equals(s.getState());
    }

    // template<class T>
    bool operator<(const State<T> &p1) {
        return p1.getCost() < this->getCost();
    }

    bool operator==(State<T> p1) {
        return (p1.getState() == this->getState());
    }


    State() {}
};


#endif //EX4_STATE_H

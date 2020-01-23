//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T> dad;
    bool visited;
public:
    virtual ~State() {

    }

    T getState() const {
        return state;
    }

    void setCost(double cost) {
        State::cost = cost;
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


    State(T state1) : state(state1),visited(false),cost(0){}



    bool equals(State<T> s){
        state.equals(s.getState());
    }
   // template<class T>
   bool operator<(const State<T>& p1) {
       return p1.getCost() < this->getCost();
   }

};


#endif //EX4_STATE_H

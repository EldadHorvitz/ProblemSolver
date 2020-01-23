//
// Created by eldad on 23/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <class T>
class State {
private:
    T *state;
    double cost;
    double costSum;
    double uCostSum;
    State<T>* dad;
    bool visited;
public:
    virtual ~State() {

    }

    double getUCostSum() const {
        return uCostSum;
    }

    void setUCostSum(double uCostSum1) {
        State::uCostSum = uCostSum1;
    }

    void setVisited(bool visited1) {
        State::visited = visited1;
    }

    double getCost() const {
        return cost;
    }

    bool isVisited() const {
        return visited;
    }


    void setDad(State<T> *dad) {
        State::dad = dad;
    }

    double getCostSum() const {
        return costSum;
    }

    T *getState() const {
        return state;
    }

    State<T> *getDad() const {
        return dad;
    }

    void setCostSum(double costSum1) {
        State::costSum = costSum1;
    }


    bool equals(State<T> *s){
        state->equals(s->getState());
    }
   // template<class T>
   bool operator<( State<T>* p1) {
       return p1->getCostSum() < this->getCostSum();
   }
    bool operator==(State<T>* p1) {
        return (p1->getState() == this->getState());
    }

};


#endif //EX4_STATE_H

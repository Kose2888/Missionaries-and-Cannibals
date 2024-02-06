#ifndef ACTIONS_H
#define ACTIONS_H

#include <iostream>
#include <vector>

#include "State.h"
#include "Node.h"


class Actions {
  private:

  public:
    std::vector<State> allStates;
    Actions();

    ~Actions();

    void storeState(Node *);

    bool isStatesEqual(State , Node *);

    bool isRepeatedState(Node *);

    //Sucessor Functions
    void mvOneC(Node *);

    void mvTwoC(Node *);

    void mvOneM(Node *);

    void mvTwoM(Node *);

    void mvBoth(Node *);
};


#endif

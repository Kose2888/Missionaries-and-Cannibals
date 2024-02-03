#ifndef ACTIONS_H
#define ACTIONS_H

#include <iostream>
#include <vector>
#include "Node.h"


class Actions {
  private:

  public:
    Actions();

    ~Actions();

    //Sucessor Functions
    void mvOneC(Node *);

    void mvTwoC(Node *);

    void mvOneM(Node *);

    void mvTwoM(Node *);

    void mvBoth(Node *);
};


#endif

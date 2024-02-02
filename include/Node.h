#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "State.h"

class Node {
  private:
    int id;
    Node *parent;
    std::vector<Node *> children;

    State s;

  public:
    Node();

    ~Node();

    void addChild(Node *child);
};

#endif

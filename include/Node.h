#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

#include "State.h"

class Node {
  public:
    int id;
    Node *parent;
    std::vector<Node *> children;
    State s;

    Node();

    ~Node();

    void addChild(Node *child);
};

#endif

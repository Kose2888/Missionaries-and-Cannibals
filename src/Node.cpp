#include "Node.h"

Node::Node() {
  int id = 0;
  parent = NULL;
}

Node::~Node() {
  for(int i = 0; i < children.size(); i++) {
    delete children[i];
  }
}

void Node::addChild(Node *child) {
  child->id = this->id + 1;
  child->parent = this;
  children.push_back(child);
}

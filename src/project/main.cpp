#include <iostream>

#include "State.h"
#include "Actions.h"
#include "Node.h"


Node* bfs(Node *, Actions *);

int main (int argc, char *argv []) {
  Node *root = new Node;
  Actions *a = new Actions;

  root->s.setState(3, 0, 3, 0, 0);
  a->storeState(root);

  a->mvOneC(root);
  a->mvOneM(root);
  a->mvTwoC(root);
  a->mvTwoM(root);
  a->mvBoth(root);

  root->s.viewState();
  for(int i = 0; i <= root->children.size() -1; i++){
    root->children[i]->s.viewState();
    a->storeState(root->children[i]);
  }

  Node *goal;
  goal = bfs(root, a);

  std::cout << "Output the goal" << std::endl;
  goal->s.viewState();


  delete root;
  delete a;
}

Node* bfs(Node *n, Actions *a){

  if(n->s.isGoalState() == true) {
    std::cout << "TESTTTT" << std::endl;
    return n;
  }

  if(n->children.size() != 0) {
    std::cout << "Before for loop" << std::endl;
    for(int i = 0; i <= n->children.size() - 1; i++){
      std::cout << "In for loop" << std::endl;

      if(n->children[i]->s.isGoalState()) {
        std::cout << "Goal State has been found!" << std::endl;
        n->children[i]->s.viewState();
        return n->children[i];
      }

      a->mvOneC(n->children[i]);
      a->storeState(n->children[i]);

      a->mvOneM(n->children[i]);
      a->storeState(n->children[i]);

      a->mvTwoC(n->children[i]);
      a->storeState(n->children[i]);

      a->mvTwoM(n->children[i]);
      a->storeState(n->children[i]);

      a->mvBoth(n->children[i]);
      a->storeState(n->children[i]);

      n->children[i]->s.viewState();
    }
    for(int i = 0; i <= n->children.size() - 1; i++){
      if(bfs(n->children[i], a)->s.isGoalState() != true)
        continue;
      else
        return n->children[i];
    }
  }
  return n->parent;
}

#include <iostream>

#include "State.h"
#include "Actions.h"
#include "Node.h"

int main (int argc, char *argv []) {
  Node *root = new Node;
  Actions *a = new Actions;

  root->s.setState(3, 0, 3, 0, 0);
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
  bool goalFound = false;
  /*
  do{


  }while(!goalFound);
  */

  delete root;
  delete a;
}

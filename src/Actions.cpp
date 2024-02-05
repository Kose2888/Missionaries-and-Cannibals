#include "Actions.h"

Actions::Actions() {
}

Actions::~Actions() {
}

void Actions::mvOneC(Node *n) {
  //Somewhere have to check for repeated states

  if(n->s.getBoat() == 0) { //Boat on left side
    Node *child = new Node;
    n->addChild(child);

    //Check if moving one cannibal is legal
    if(n->s.getlC() != 0 && n->s.getrC() != 3){
    child->s.setlC(n->s.getlC() - 1);
    child->s.setrC(n->s.getrC() + 1);
    child->s.setBoat(1); //Boat has moved to right side now
    }
    return;
  }
  if(n->s.getBoat() == 1) { //Boat on right side
    Node *child = new Node;
    n->addChild(child);

    //Check if moving one cannibal is legal
    if(n->s.getlC() != 3 && n->s.getrC() != 0){
    child->s.setlC(n->s.getlC() + 1);
    child->s.setrC(n->s.getrC() - 1);
    child->s.setBoat(0); //Boat has moved to right side now
    }
    return;
  }
  else {
    std::cout << "Error: Could not move one Cannibal" << std::endl;
  }
}

void Actions::mvTwoC(Node *n) {
}

void Actions::mvOneM(Node *n) {
}

void Actions::mvTwoM(Node *n) {
}

void Actions::mvBoth(Node *n) {
}

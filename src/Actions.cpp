#include "Actions.h"

Actions::Actions() {
}

Actions::~Actions() {
}

void Actions::storeState(Node *n) {
  State s;

  s.setlM(n->s.getlM());
  s.setrM(n->s.getrM());
  s.setlC(n->s.getlC());
  s.setrC(n->s.getrC());
  s.setBoat(n->s.getBoat());
  allStates.push_back(s);
}

bool Actions::isStatesEqual(State s, Node *n) {
  if(s.getlM() == n->s.getlM() &&
     s.getrM() == n->s.getrM() &&
     s.getlC() == n->s.getlC() &&
     s.getrC() == n->s.getrC() &&
     s.getBoat() == n->s.getBoat())
    return true;
  else
    return false;
}

bool Actions::isRepeatedState(Node *n) {
  if(allStates.size() != 0){
    for(int i = 0; i <= allStates.size(); i++) {
      if(isStatesEqual(allStates[i], n))
        return true;
    }
    return false;
  }
    return false;
}

void Actions::mvOneC(Node *n) {
  if(n->s.getBoat() == 0) { //Boat on left side
                            //Check if moving one cannibal is legal
    if(n->s.getlC() != 0 && n->s.getrC() != 3){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlC(n->s.getlC() - 1);
      child->s.setrC(n->s.getrC() + 1);
      child->s.setBoat(1); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered()) {
        n->children.pop_back();
      }
    }
    return;
  }
  if(n->s.getBoat() == 1) { //Boat on right side
                            //Check if moving one cannibal is legal
    if(n->s.getlC() != 3 && n->s.getrC() != 0){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlC(n->s.getlC() + 1);
      child->s.setrC(n->s.getrC() - 1);
      child->s.setBoat(0); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
  else {
    //std::cout << "Error: Could not move one Cannibal" << std::endl;
  }
}

void Actions::mvTwoC(Node *n) {
  if(n->s.getBoat() == 0) { //Boat on left side
                            //Check if moving one cannibal is legal
    if(n->s.getlC() >= 2 && n->s.getrC() <= 1){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlC(n->s.getlC() - 2);
      child->s.setrC(n->s.getrC() + 2);
      child->s.setBoat(1); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
  if(n->s.getBoat() == 1) { //Boat on right side
                            //Check if moving one cannibal is legal
    if(n->s.getlC() <= 1 && n->s.getrC() >= 2){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlC(n->s.getlC() + 2);
      child->s.setrC(n->s.getrC() - 2);
      child->s.setBoat(0); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
}

void Actions::mvOneM(Node *n) {
  if(n->s.getBoat() == 0) { //Boat on left side
                            //Check if moving one cannibal is legal
    if(n->s.getlM() != 0 && n->s.getrM() != 3){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlM(n->s.getlM() - 1);
      child->s.setrM(n->s.getrM() + 1);
      child->s.setBoat(1); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered()){
        n->children.pop_back();
      }
      return;
    }
  }
  if(n->s.getBoat() == 1) { //Boat on right side
                            //Check if moving one cannibal is legal
    if(n->s.getlM() != 3 && n->s.getrM() != 0){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlM(n->s.getlM() + 1);
      child->s.setrM(n->s.getrM() - 1);
      child->s.setBoat(0); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
}

void Actions::mvTwoM(Node *n) {
  if(n->s.getBoat() == 0) { //Boat on left side
                            //Check if moving one cannibal is legal
    if(n->s.getlM() >= 2 && n->s.getrM() <= 1){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlM(n->s.getlM() - 2);
      child->s.setrM(n->s.getrM() + 2);
      child->s.setBoat(1); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
  if(n->s.getBoat() == 1) { //Boat on right side
                            //Check if moving one cannibal is legal
    if(n->s.getlM() <= 1 && n->s.getrM() >= 2){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlM(n->s.getlM() + 2);
      child->s.setrM(n->s.getrM() - 2);
      child->s.setBoat(0); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
}

void Actions::mvBoth(Node *n) {
  if(n->s.getBoat() == 0) { //Boat on left side
                            //Check if moving one cannibal is legal
    if(n->s.getlM() != 0 && n->s.getrM() != 3 &&
       n->s.getlC() != 0 && n->s.getrC() != 3){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlM(n->s.getlM() - 1);
      child->s.setrM(n->s.getrM() + 1);
      child->s.setlC(n->s.getlC() - 1);
      child->s.setrC(n->s.getrC() + 1);
      child->s.setBoat(1); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
  if(n->s.getBoat() == 1) { //Boat on right side
                            //Check if moving one cannibal is legal
    if(n->s.getlM() != 3 && n->s.getrM() != 0 &&
       n->s.getlC() != 3 && n->s.getrC() != 0){
      Node *child = new Node;
      n->addChild(child);
      child->s.setlM(n->s.getlM() + 1);
      child->s.setrM(n->s.getrM() - 1);
      child->s.setlC(n->s.getlC() + 1);
      child->s.setrC(n->s.getrC() - 1);
      child->s.setBoat(1); //Boat has moved to right side now

      if(isRepeatedState(child) || child->s.isOutNumbered())
        n->children.pop_back();
    }
    return;
  }
}

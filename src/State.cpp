#include "State.h"

State::State() {
  lM = 0;
  rM = 0;
  lC = 0;
  rC = 0;
  boat = 0;
  boatPassengers = "";
}

State::~State() {
}

void State::setState(int lMis, int rMis, int lCan, int rCan, int b) {
  lM = lMis;
  rM = rMis;
  lC = lCan;
  rC = rCan;
  boat = b;
}

void State::viewState() {
  std::cout << "Left Missionaries = " << lM << "\n"
    << "Left Cannibals = " << lC << "\n" << std::endl;

  std::cout << "Right Missionaries = " << rM << "\n"
    << "Right Cannibals = " << rC << "\n" << std::endl;

  if (boat == 0)
    std::cout << "Boat is on left side" << std::endl;
  else
    std::cout << "Boat is on right side" << std::endl;
}

bool State::isStartState() {
  if (lM == 3 && rM == 0 && lC == 3 && rC == 0 && boat == 0)
   return true;
  else
   return false;
}

bool State::isGoalState() {
  if (lM == 0 && rM == 3 && lC == 0 && rC == 3 && boat == 1)
   return true;
  else
   return false;
}

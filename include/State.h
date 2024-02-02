#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>

class State {
  private:
    int lM, rM, lC, rC;
    int boat = 0;
    std::string boatPassengers;

  public:
    State();

    ~State();

};



#endif

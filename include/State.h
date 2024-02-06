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

    void setlM(int);

    void setrM(int);

    void setlC(int);

    void setrC(int);

    void setBoat(int);

    int getlM() const {return lM;}

    int getrM() const {return rM;}

    int getlC() const {return lC;}

    int getrC() const {return rC;}

    int getBoat() const {return boat;}

    void setState(int lM, int rM, int lC, int rC, int boat);

    void viewState();

    bool isStartState();

    bool isGoalState();

    bool isOutNumbered();

};



#endif

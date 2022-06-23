#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

#include "generator.hh"

class MyActionInitialization : public G4VUserActionInitialization {
public:
  MyActionInitialization();
  ~MyActionInitialization();

  virtual void Build() const; // runs the particle gun, compute the steps and so on
  
};
#endif

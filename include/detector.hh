#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"

class MySensitiveDetector : public G4VSensitiveDetector {
public:
  MySensitiveDetector(G4String);
  ~MySensitiveDetector();

  private:
  // main function to detect something/process data
  virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

};
#endif

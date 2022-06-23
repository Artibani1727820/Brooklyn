#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh" // allows to use pre-implemented units (e.g. m, degree, ...)
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction {
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction();

  virtual G4VPhysicalVolume *Construct(); // detector construction

private:
  std::vector<G4VisAttributes*> fVisAttributes;
  //G4LogicalVolume *fLogicFibre[4] = {nullptr,nullptr,nullptr,nullptr};
  G4LogicalVolume *fLogicFibre1;
  G4LogicalVolume *fLogicFibre05;
  G4LogicalVolume *fLogicFibre025;
  G4LogicalVolume *fLogicFibre02;
  virtual void ConstructSDandField();
};

#endif


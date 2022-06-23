#include "physics.hh"

MyPhysicsList::MyPhysicsList() {
  // defining needed physics
  RegisterPhysics(new G4EmStandardPhysics()); // EM interactions
  RegisterPhysics(new G4OpticalPhysics()); // optical photons
}

MyPhysicsList::~MyPhysicsList() {}

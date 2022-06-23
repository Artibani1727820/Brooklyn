#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.cc"
#include "physics.cc"
#include "action.cc"
#include "generator.cc"
#include "detector.cc"

int main(int argc, char** argv) {

  // Standard Template
  
  G4UIExecutive* ui = nullptr;
  if ( argc == 1 ) { ui = new G4UIExecutive(argc, argv); }
  
  G4RunManager *runManager = new G4RunManager();
  
  runManager->SetUserInitialization(new MyDetectorConstruction());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());
  
  runManager->Initialize();
  
  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();
  
  G4UImanager *UImanager =  G4UImanager::GetUIpointer();
  
  /*UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 0 0");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autorefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate -1");
  UImanager->ApplyCommand("/vis/scene/add/axes 0 0 0 20 mm");*/
  
  
  //ui->SessionStart();

  if ( ! ui ) {
    // batch mode
    G4String command = "/run/beamOn ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else {
    // interactive mode
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 0 0");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autorefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate -1");
    UImanager->ApplyCommand("/vis/scene/add/axes 0 0 0 20 mm");
    
    ui->SessionStart();

    delete ui;
  }

  //delete ui;
  delete runManager;
  delete visManager;
  
  return 0;
}

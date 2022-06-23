#include "detector.hh"
#include "G4RunManager.hh"


MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}
MySensitiveDetector::~MySensitiveDetector() {}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) {
  G4Track *track = aStep->GetTrack();

  //track->SetTrackStatus(fStopAndKill); // as soon as the photon enters the det it is killed
  
  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  //G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4ThreeVector posPhoton = preStepPoint->GetPosition();

  //G4cout << "Photon position: " << posPhoton << G4endl;

  const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable(); // touchable of our physical volume

  G4int copyNo = touchable->GetCopyNumber(); // it gets the copy no. of our physical det (i.e. i and j)
  
  G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
  

  /* G4VPhysicalVolume *physVol = touchable->GetVolume();
     G4ThreeVector posDetector = physVol->GetTranslation();*/

  //G4cout << "Detector position: " << posDetector << G4endl;
  G4int id = track->GetTrackID();


  G4double eDep = aStep->GetTotalEnergyDeposit();
 
  G4cout <<  eventID << G4endl;
  
  static std::ofstream stuff("stuff.txt");
 

  /*if(copyNo == 0) {
    stuff << "#Nuovo Evento" << std::endl;
    }*/

  if (eDep > 0) {
    stuff << copyNo << "\t" << eDep/keV << "\t" << id << "\t" << eventID << std::endl;
  }
  
  return true;
}

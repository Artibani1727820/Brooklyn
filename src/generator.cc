#include <cmath>
#include <random>

#define _USE_MATH_DEFINES

MyPrimaryGenerator::MyPrimaryGenerator() {
  fParticleGun = new G4ParticleGun(1); // one primary vertex per event is created
}

MyPrimaryGenerator::~MyPrimaryGenerator() {
  delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent) {
  // what kind of particle we want to create
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();

  
  // shooting a particle
  G4String particleName = "mu+";
  G4ParticleDefinition *particle = particleTable->FindParticle(particleName);

  G4double h = 2.*cm;
  G4double l = 1.6*cm;
  G4double d = 20*cm;
  G4double theta = 40*degree;

  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator

  std::uniform_real_distribution<double> distr_phi(0, 2*M_PI);
  G4double phi = distr_phi(gen);
  
  G4double rmax = 0;
  G4double rmin = 0;  

  if (phi == M_PI*0.5 || phi == M_PI*1.5) {
    rmax = d*0.5 + h*tan(theta);
    rmin = -d*0.5 + (l+h)*tan(theta);
  } else {
    rmax = l/abs(cos(phi))*0.5 + h*tan(theta);
    rmin = -l/abs(cos(phi))*0.5 + (l+h)*tan(theta);
  }
  
  G4double y = h+l*0.5;

  std::uniform_real_distribution<double> distr_r(rmin, rmax); // define the range
  G4double r = distr_r(gen);  

  G4double z = r*cos(phi);
  
  /*std::uniform_int_distribution<int> distr_step(-2, 2);
    G4int step = distr_step(gen);*/
  G4double x = r*sin(phi); //+ step*rmax;

  G4ThreeVector pos(x,y,z);
  // defining particle momentum direction
  G4double xdir = -sin(theta)*sin(phi);
  G4double zdir = -sin(theta)*cos(phi);
  /*G4double xdir = -sin(theta)*x/r;
    G4double zdir = -sin(theta)*z/r;*/

  
  G4ThreeVector mom(xdir,-cos(theta),zdir);

  fParticleGun->SetParticlePosition(pos);
  fParticleGun->SetParticleMomentumDirection(mom);
  fParticleGun->SetParticleMomentum(1*GeV); // MeV by default
  fParticleGun->SetParticleDefinition(particle);

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

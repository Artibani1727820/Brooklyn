#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction() {}

MyDetectorConstruction::~MyDetectorConstruction() {
  for (auto visAttributes: fVisAttributes) {
    delete visAttributes;
  }
}

G4VPhysicalVolume *MyDetectorConstruction::Construct() {


  // Geometry -----------------------------------------------------------------------------------------

  
  G4int fNbOfPlanes = 16;
  G4int fNbOfFibres[16] = {};

  G4double fibreLength = 20*cm;
  G4double fibreSize[16] = {};
  G4double fibreSpacing = 1.;

  G4double mylarLength = 20*cm;
  G4double mylarThickness = 0.05;
  G4double mylarWidth = 16;
  
  G4double trackerSize = fNbOfPlanes*1.; // 16mm*1mm

  // starting positions
  G4double yPos = (trackerSize - 1.)*0.5;
  G4double zPos[16] = {};
  G4double mylarZPos = 0.;

  
  // Building Materials --------------------------------------------------------------------------------

  G4NistManager *nist = G4NistManager::Instance();


  /////////////
  ////World////
  /////////////

  G4double worldLengthXYZ = 1.2 * fibreLength;
  
  // world material
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  G4Box *solidWorld = new G4Box("solidWorld", worldLengthXYZ/2.,  worldLengthXYZ/2.,  worldLengthXYZ/2.);
  
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);


  // world visualization attributes -------------------------------------------------------------
  
  auto visAttributes = new G4VisAttributes(G4Colour(1.0,1.0,1.0));
  visAttributes->SetVisibility(false);
  logicWorld->SetVisAttributes(visAttributes);
  fVisAttributes.push_back(visAttributes);
  

  //////////////
  ////Mylar/////
  //////////////

  // mylar material
  G4Material *mylarMat = nist->FindOrBuildMaterial("G4_MYLAR");

  // Upper Layers
  
  G4Box *mylarWorld = new G4Box("mylarWorld", mylarLength/2., mylarThickness/2., mylarWidth/2.);

  G4LogicalVolume* fLogicMylar =  new G4LogicalVolume(mylarWorld,mylarMat,"Mylar");
  
 
  //////////////
  ////Fibres////
  //////////////

  // fibres material
  G4Material *fibreMat = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
  
  
  ////////////////
  ////Supports////
  ////////////////

// supports material
  G4Material *suppMat = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
  
  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  

  for (G4int plane=0; plane<fNbOfPlanes; plane++) {

    if (plane == 0 || plane == 1 || plane == 14 || plane == 15) {
      fibreSize[plane] = 0.1*cm;
    }
       
    if (plane == 2 || plane == 3 || plane == 12 || plane == 13) {
      fibreSize[plane] = 0.5;  
    }
    
    if (plane == 4 || plane == 5 || plane == 9 || plane == 10 || plane == 11) {
      fibreSize[plane] = 0.25;
    }
    
    if (plane == 6 || plane == 7 || plane == 8) {
      fibreSize[plane] = 0.20;
    }
    
    zPos[plane] = (-trackerSize + fibreSize[plane])*0.5;
    
    fNbOfFibres[plane] = G4int(16. / fibreSize[plane]);

  }

  
  // defining fibres logicDetectors ---------------------------------------------------------------------

  G4Box *fibreWorld1 = new G4Box("fibreWorld1", fibreLength/2., fibreSize[0]/2., fibreSize[0]/2.);
  fLogicFibre1 = new G4LogicalVolume(fibreWorld1,fibreMat,"Fibre1");

  G4Tubs *tubfibreWorld = new G4Tubs("tubfibreWorld",0,fibreSize[2]*0.5,fibreLength*0.5,0.*deg,360.*deg);
  fLogicFibre05 =  new G4LogicalVolume(tubfibreWorld,fibreMat,"Fibre05");

  G4Box *fibreWorld025 = new G4Box("fibreWorld025", fibreLength/2., fibreSize[4]/2., fibreSize[4]/2.);
  fLogicFibre025 = new G4LogicalVolume(fibreWorld025,fibreMat,"Fibre025");

  G4Box *fibreWorld02 = new G4Box("fibreWorld02", fibreLength/2., fibreSize[6]/2., fibreSize[6]/2.);
  fLogicFibre02 = new G4LogicalVolume(fibreWorld02,fibreMat,"Fibre02");



  // defining Supports ----------------------------------------------------------------------------------
   
  G4Box *suppWorld0 = new G4Box("suppWorld0", mylarLength/2., 0.25/2., mylarWidth/2.);
  G4LogicalVolume* fLogicSupp0 = new G4LogicalVolume(suppWorld0,suppMat,"Support0");
  
  G4Box *suppWorld1 = new G4Box("suppWorld1", mylarLength/2., 0.5/2., mylarWidth/2.);
  G4LogicalVolume* fLogicSupp1 = new G4LogicalVolume(suppWorld1,suppMat,"Support1");
  
  G4Box *suppWorld2 = new G4Box("suppWorld2", mylarLength/2., 0.625/2., mylarWidth/2.);
  G4LogicalVolume* fLogicSupp2 = new G4LogicalVolume(suppWorld2,suppMat,"Support2");
  
  G4Box *suppWorld3 = new G4Box("suppWorld3", mylarLength/2., 0.75/2., mylarWidth/2.);
  G4LogicalVolume* fLogicSupp3 = new G4LogicalVolume(suppWorld3,suppMat,"Support3");
  
  G4Box *suppWorld4 = new G4Box("suppWorld4", mylarLength/2., 0.775/2., mylarWidth/2.);
  G4LogicalVolume* fLogicSupp4 = new G4LogicalVolume(suppWorld4,suppMat,"Support4");
  
  G4Box *suppWorld5 = new G4Box("suppWorld5", mylarLength/2., 0.8/2., mylarWidth/2.);
  G4LogicalVolume* fLogicSupp5 = new G4LogicalVolume(suppWorld5,suppMat,"Support5");
   
   

  // building of fibres matrix -------------------------------------------------------------------

  ///////////////////////////////////////////////////
  /////////// vertical (y) development //////////////
  ///////////////////////////////////////////////////
  for (G4int plane=0; plane<fNbOfPlanes; plane++) {
       

    ///////////////////////////
    ///////upper mylar/////////
    ///////////////////////////

    new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, yPos+0.5*(fibreSize[plane]+mylarThickness), mylarZPos), // at (x,y,z)
		      fLogicMylar,        // its logical volume
		      "MylarUp",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      plane,                       // copy number
		      true);              // checking overlaps

    
    /////////////////////////////////////////////////////
    /////////// horizontal (z) development //////////////
    /////////////////////////////////////////////////////
    for (G4int fib=0; fib<fNbOfFibres[plane]; fib++) {

      G4ThreeVector pos = G4ThreeVector(0, yPos, zPos[plane]);
      
      if (plane == 2 || plane == 3 || plane == 12 || plane == 13) {   // circular fibres

	G4RotationMatrix* fieldRot = new G4RotationMatrix();
        fieldRot->rotateX(90.*deg);
	fieldRot->rotateY(90.*deg);
	
	new G4PVPlacement(fieldRot,                            // no rotation
			  pos, // at (x,y,z)
			  fLogicFibre05,        // its logical volume
			  "Fibre",                 // its name
			  logicWorld,                    // its mother  volume
			  false,                        // no boolean operations
			  plane,                       // copy number
			  true);              // checking overlaps
	// fibres visualization attributes -------------------------------------------------------------
	
	visAttributes = new G4VisAttributes(G4Colour(0.6,0.8,1));
	fLogicFibre05->SetVisAttributes(visAttributes);
	fVisAttributes.push_back(visAttributes);
	
      }
      else {                                                              // squared fibres

	 if (plane == 0 || plane == 1 || plane == 14 || plane == 15) {
	   new G4PVPlacement(0,                            // no rotation
			   pos, // at (x,y,z)
			   fLogicFibre1,        // its logical volume
			   "Fibre",                 // its name
			   logicWorld,                    // its mother  volume
			   false,                        // no boolean operations
			   plane,                       // copy number
			   true);              // checking overlaps
	 }
    
	 if (plane == 4 || plane == 5 || plane == 9 || plane == 10 || plane == 11) {
	   new G4PVPlacement(0,                            // no rotation
			   pos, // at (x,y,z)
			   fLogicFibre025,        // its logical volume
			   "Fibre",                 // its name
			   logicWorld,                    // its mother  volume
			   false,                        // no boolean operations
			   plane,                       // copy number
			   true);              // checking overlaps
	 }
    
	 if (plane == 6 || plane == 7 || plane == 8) {
	   new G4PVPlacement(0,                            // no rotation
			   pos, // at (x,y,z)
			   fLogicFibre02,        // its logical volume
			   "Fibre",                 // its name
			   logicWorld,                    // its mother  volume
			   false,                        // no boolean operations
			   plane,                       // copy number
			   true);              // checking overlaps
	 }
	 
	// fibres visualization attributes -------------------------------------------------------------

	if (plane == 4 || plane == 5 || plane == 9 || plane == 10 || plane == 11) {    // 0.25
	  visAttributes = new G4VisAttributes(G4Colour(0.6,1,0.8));
	  fLogicFibre025->SetVisAttributes(visAttributes);
	  fVisAttributes.push_back(visAttributes);
	}

	if (plane == 6 || plane == 7 || plane == 8) {   // 0.20
	  visAttributes = new G4VisAttributes(G4Colour(1,1,0.6));
	  fLogicFibre02->SetVisAttributes(visAttributes);
	  fVisAttributes.push_back(visAttributes);
	}

	if (plane == 0 || plane == 1 || plane == 14 || plane == 15) {  // 1.0
	  visAttributes = new G4VisAttributes(G4Colour(1,0.6,0.6));
	  fLogicFibre1->SetVisAttributes(visAttributes);
	  fVisAttributes.push_back(visAttributes);
	}
	
      }
      
      
      zPos[plane] += fibreSize[plane];

    } // end of horizontal development


    ///////////////////////////
    ///////lower mylar/////////
    ///////////////////////////

    new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, yPos-0.5*(fibreSize[plane]+mylarThickness), mylarZPos), // at (x,y,z)
		      fLogicMylar,        // its logical volume
		      "MylarDown",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      plane,                       // copy number
		      true);              // checking overlaps
    
    yPos -= fibreSpacing + 0.1;

    // mylar visualization attributes -------------------------------------------------------------
    
    visAttributes = new G4VisAttributes(G4Colour(0.9,0.9,0.9));   // LightGray
    fLogicMylar->SetVisAttributes(visAttributes);
    fVisAttributes.push_back(visAttributes);
    
  } // end of vertical development

  
  
  // building of supports
  
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, 5.725, mylarZPos), // at (x,y,z)
		      fLogicSupp0,        // its logical volume
		      "Support0",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
    
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, 4.75, mylarZPos), // at (x,y,z)
		      fLogicSupp1,        // its logical volume
		      "Support1",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
		      
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, 3.5875, mylarZPos), // at (x,y,z)
		      fLogicSupp2,        // its logical volume
		      "Support2",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
  
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, 2.55, mylarZPos), // at (x,y,z)
		      fLogicSupp3,        // its logical volume
		      "Support3",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
  
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, 1.4375, mylarZPos), // at (x,y,z)
		      fLogicSupp4,        // its logical volume
		      "Support4",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
    
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, 0.35, mylarZPos), // at (x,y,z)
		      fLogicSupp5,        // its logical volume
		      "Support5",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
		      
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -0.75, mylarZPos), // at (x,y,z)
		      fLogicSupp5,        // its logical volume
		      "Support6",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
  
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -1.8375, mylarZPos), // at (x,y,z)
		      fLogicSupp4,        // its logical volume
		      "Support7",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps 
  
   new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -2.95, mylarZPos), // at (x,y,z)
		      fLogicSupp3,        // its logical volume
		      "Support8",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
    
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -4.05, mylarZPos), // at (x,y,z)
		      fLogicSupp3,        // its logical volume
		      "Support9",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
		      
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -5.0875, mylarZPos), // at (x,y,z)
		      fLogicSupp2,        // its logical volume
		      "Support10",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
  
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -6.25, mylarZPos), // at (x,y,z)
		      fLogicSupp1,        // its logical volume
		      "Support11",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps
		      
  new G4PVPlacement(0,                            // no rotation
		      G4ThreeVector(0, -7.225, mylarZPos), // at (x,y,z)
		      fLogicSupp0,        // its logical volume
		      "Support12",                 // its name
		      logicWorld,                    // its mother  volume
		      false,                        // no boolean operations
		      0,                       // copy number
		      true);              // checking overlaps	
		      
  // support visualization attributes -------------------------------------------------------------
    
  visAttributes = new G4VisAttributes(G4Colour(0.0,0.0,0.5));
  fLogicSupp0->SetVisAttributes(visAttributes);
  fLogicSupp1->SetVisAttributes(visAttributes);
  fLogicSupp2->SetVisAttributes(visAttributes);
  fLogicSupp3->SetVisAttributes(visAttributes);
  fLogicSupp4->SetVisAttributes(visAttributes);
  fLogicSupp5->SetVisAttributes(visAttributes);
  fVisAttributes.push_back(visAttributes);
    	      
		       
  return physWorld;
}


void MyDetectorConstruction::ConstructSDandField() {
  MySensitiveDetector * sensDet = new MySensitiveDetector("SensitiveDetector");

  fLogicFibre1->SetSensitiveDetector(sensDet);
  fLogicFibre05->SetSensitiveDetector(sensDet);
  fLogicFibre025->SetSensitiveDetector(sensDet);
  fLogicFibre02->SetSensitiveDetector(sensDet);
}

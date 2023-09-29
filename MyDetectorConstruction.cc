#include "MyDetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{ }

MyDetectorConstruction::~MyDetectorConstruction()
{ }

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{

  G4NistManager* nist = G4NistManager::Instance();
/*
  G4Material* SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2);
  SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
  SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

  G4Material* H2O = new G4Material("HO2", 1.00*g/cm3, 2);
  H2O->AddElement(nist->FindOrBuildElement("H"), 1);
  H2O->AddElement(nist->FindOrBuildElement("O"), 2);

  G4Element* C = nist->FindOrBuildElement("C");

  G4Material* Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
  Aerogel->AddMaterial(SiO2, 62.5*perCent);
  Aerogel->AddMaterial(H2O, 37.4*perCent);
  Aerogel->AddElement(C, 0.1*perCent);

  G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
  G4double rindexAerogel[2] = {1.1, 1.1};
  G4double rindexWorld[2] = {1.0, 1.0};

  G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
  mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);

  Aerogel->SetMaterialPropertiesTable(mptAerogel);
*/
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_H");
  /*
  new G4Material("H",0.083748*kg/m3,1,kStateGas,293*kelvin,1*atmosphere);
  world_mat->AddElement(nist->FindOrBuildElement("H"),2);
  */
/*
  G4MaterialPropertiesTable* mptWorld = new G4MaterialPropertiesTable();
  mptWorld->AddProperty("RINDEX" , energy, rindexWorld, 2);

  world_mat->SetMaterialPropertiesTable(mptWorld);
*/
/*
G4_H density = 8.3748e-05 (g/cm^3)
G4_H I(ev) = 19.2
https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Appendix/materialNames.html
*/

  G4double t = 0.000001;
  G4Box* solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, (5.0 + 2*t)*m);

  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, world_mat, "logicWorld");

  G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "physWorld", 0, false, 0, true);

  //G4Box* solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m);

  //G4LogicalVolume* logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator");

  //G4VPhysicalVolume* physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);

  G4Box* solidDetector = new G4Box("solidDetector",0.5*m,0.5*m, t*m);
  // 0.05*m, 0.05*m, 0.01*m);

  logicDetector = new G4LogicalVolume(solidDetector, world_mat, "logicDetector");
  G4VPhysicalVolume* physDetector0 = new G4PVPlacement(0, G4ThreeVector(0, 0, -(5.0 - t)*m), logicDetector, "physDetector", logicWorld, false, 1, true);

  G4VPhysicalVolume* physDetector1 = new G4PVPlacement(0, G4ThreeVector(0, 0, -(4.0 - t)*m), logicDetector, "physDetector", logicWorld, false, 2, true);

  G4VPhysicalVolume* physDetector2 = new G4PVPlacement(0, G4ThreeVector(0, 0, -(3.0 - t)*m), logicDetector, "physDetector", logicWorld, false, 3, true);

  G4VPhysicalVolume* physDetector3 = new G4PVPlacement(0, G4ThreeVector(0, 0, -(2.0 - t)*m), logicDetector, "physDetector", logicWorld, false, 4, true);

  G4VPhysicalVolume* physDetector4 = new G4PVPlacement(0, G4ThreeVector(0, 0, -(1.0 - t)*m), logicDetector, "physDetector", logicWorld, false, 5, true);

  G4VPhysicalVolume* physDetector5 = new G4PVPlacement(0, G4ThreeVector(0, 0, t*m), logicDetector, "physDetector", logicWorld, false, 6, true);

  G4VPhysicalVolume* physDetector6 = new G4PVPlacement(0, G4ThreeVector(0, 0, (1.0 + t)*m), logicDetector, "physDetector", logicWorld, false, 7, true);

  G4VPhysicalVolume* physDetector7 = new G4PVPlacement(0, G4ThreeVector(0, 0, (2.0 + t)*m), logicDetector, "physDetector", logicWorld, false, 8, true);

  G4VPhysicalVolume* physDetector8 = new G4PVPlacement(0, G4ThreeVector(0, 0, (3.0 + t)*m), logicDetector, "physDetector", logicWorld, false, 9, true);

  G4VPhysicalVolume* physDetector9 = new G4PVPlacement(0, G4ThreeVector(0, 0, (4.0 + t)*m), logicDetector, "physDetector", logicWorld, false, 10, true);

  G4VPhysicalVolume* physDetector10 = new G4PVPlacement(0, G4ThreeVector(0, 0, (5.0 + t)*m), logicDetector, "physDetector", logicWorld, false, 11, true);

  //G4VPhysicalVolume* physDetector10 = new G4PVPlacement(0, G4ThreeVector(0, 0, (5.0 + t)*m), logicDetector, "physDetector", logicWorld, false, 0, true);
  //G4VPhysicalVolume* physDetector9 = new G4PVPlacement(0, G4ThreeVector(0, 0, 5.0*m), logicDetector, "physDetector", logicWorld, false, 0, true);
/*  for(G4int i = 0; i < 10; i++)
  {
    for(G4int j = 0; j < 10; j++)
    {
      G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m + (i+0.5)*m/10, -0.5*m + (j+0.5)*m/10, 0.49*m), logicDetector, "physDetector", logicWorld, false, (i + j)*10, true);
    }
  }
*/
/*
G4double maxStep = .24*m;//0.5*mm;
G4UserLimits *l = new G4UserLimits(maxStep);
l->SetMaxAllowedStep(maxStep);
logicWorld->SetUserLimits(l);
*/
return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
    logicDetector->SetSensitiveDetector(sensDet);
    //G4cout<<"////////////////////////////////////////////////////////////////////////////////////////////////////" <<G4endl;
}

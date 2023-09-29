#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "MyDetectorConstruction.hh"
#include "MyPhysicsList.hh"
#include "MyActionInitialization.hh"
#include "G4StepLimiterPhysics.hh"

int main(int argc, char** argv)
{
  G4RunManager *runManager = new G4RunManager();

  MyPhysicsList* MyPhysics = new MyPhysicsList();

  runManager->SetUserInitialization(new MyDetectorConstruction());
  MyPhysics->RegisterPhysics(new G4StepLimiterPhysics());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());


  runManager->Initialize();

  G4UIExecutive* ui = new G4UIExecutive(argc, argv);

  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/tracking/verbose 0");
  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate 100");
  UImanager->ApplyCommand("/tracking/storeTrajectories 0");
  ui->SessionStart();

  return 0;
}

#include "MyRunAction.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  //G4AnalysisManager *man2 = G4AnalysisManager::Instance();

  man->OpenFile("LongAll.root");
  man->CreateNtuple("Hits", "Hits");
  man->CreateNtupleIColumn("fEvent");
  man->CreateNtupleDColumn("fX2");
  man->CreateNtupleDColumn("fY2");
  man->CreateNtupleDColumn("fZ2");
  man->CreateNtupleDColumn("energy2");
  man->CreateNtupleDColumn("fX3");
  man->CreateNtupleDColumn("fY3");
  man->CreateNtupleDColumn("fZ3");
  man->CreateNtupleDColumn("energy3");
  man->FinishNtuple(0);




}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();


  man->Write();

  man->CloseFile("LongAll.root");




}

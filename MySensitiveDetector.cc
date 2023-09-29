#include "MySensitiveDetector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *R0hist)
{
  G4Track *track = aStep->GetTrack();

  //track->SetTrackStatus(fStopAndKill);

  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4ThreeVector posProton = preStepPoint->GetPosition();
  G4double energy = preStepPoint->GetKineticEnergy();
  const G4VTouchable* touchable = preStepPoint->GetTouchable();
  G4int copy_num = touchable->GetCopyNumber();

  if (track->GetParentID()== 0){
    //G4cout << "---------------------------------" << G4endl;
    //G4cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------------+" << G4endl;
    //G4cout << "|                    x-Position                    |                   y-Position                   |                    z-Position                   |"
    //G4cout << "|"<<posProton.x()                             <<  "|" << posProton.y( )<< "            " << posProton.z() << "             " << energy << "             " << copy_num << G4endl;
    G4cout <<posProton.x()                             << posProton.y( )<< "            " << posProton.z() << "             " << energy << "             " << copy_num << G4endl;
    //G4cout << "---------------------------------" << G4endl;

    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();


    G4AnalysisManager *man = G4AnalysisManager::Instance();
    //if (posProton[2] == 0){


    //G4AnalysisManager *man = G4AnalysisManager::Instance();
    if (copy_num == 4){
      man->FillNtupleIColumn(0, evt);
      man->FillNtupleDColumn(1, posProton[0]);
      man->FillNtupleDColumn(2, posProton[1]);
      man->FillNtupleDColumn(3, posProton[2]);
      man->FillNtupleDColumn(4, energy);

      };

    if (copy_num == 11){
      //man->FillNtupleIColumn(0, evt);
      man->FillNtupleDColumn(5, posProton[0]);
      man->FillNtupleDColumn(6, posProton[1]);
      man->FillNtupleDColumn(7, posProton[2]);
      man->FillNtupleDColumn(8, energy);
      man->AddNtupleRow(0);
      };









    };
return 1;
}

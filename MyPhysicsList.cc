#include "MyPhysicsList.hh"


MyPhysicsList::MyPhysicsList()
{
    RegisterPhysics (new G4EmStandardPhysics());
    //RegisterPhysics (new G4OpticalPhysics());
    //G4cout<<"////////////////////////////////////////////////////////////////////////////////////////////////////" <<G4endl;
}

MyPhysicsList::~MyPhysicsList()
{}

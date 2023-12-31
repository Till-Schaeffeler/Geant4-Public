#ifndef MYSENSITIVEDETECTOR_HH
#define MYSENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "g4root.hh"
#include "G4VTouchable.hh"


class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();

private:
    virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);
};

#endif

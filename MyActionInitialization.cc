



#include "MyActionInitialization.hh"


MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}
//rthis isdashdldkjhALKD
void MyActionInitialization::Build() const
{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}

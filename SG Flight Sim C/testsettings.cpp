#include "testsettings.h"
#include "moduledamage.h"

using namespace std;

extern bool SPACE;

testsettings::testsettings()
{
    if(SPACE == true){
        moduledamage();
    }
}

testsettings::~testsettings()
{
    //dtor
}

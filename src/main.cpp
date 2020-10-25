#include "plinko.h"

int main()
{
    //Init Game Engine
    Plinko plinko;

    //Event polling
    while (plinko.isRunning())
    {

        //BEGIN UPDATE REGION
        {
            plinko.update();
        }
        //END UPDATE REGIN

        //BEGIN RENDER REGION
        {
            plinko.render();
        }
        //END RENDER REGION
    }

    return 0;
}
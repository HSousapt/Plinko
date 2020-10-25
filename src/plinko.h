#ifndef PLINKO_H
#define PLINKO_H
/*

    GAME "ENGINE" CLASS

*/

class Plinko
{
public:
    //Constructor
    Plinko();
    //Destructor
    ~Plinko();

    //BEGIN FUNCTIONS DEFINITION REGION

    void update();

    void render();

    //END FUNCTIONS DEFINITION REGION
private:
    void init_vars();

    void init_window();
};

#endif
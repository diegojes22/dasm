/*-- Librerias --*/
// De C++
#include <iostream>
#include <string>
// My headers
#include "programController.hpp"

/*-- Main -- */
int main(int argc, char* argv[]) 
{
    ProgramController* app = new ProgramController(argc, argv);
    app->run();

    delete app;
    return 0;
}

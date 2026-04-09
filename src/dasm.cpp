/*-- Librerias --*/
// De C++
#include <iostream>
#include <string>
// My headers
#include "programController.hpp"

using namespace std;


int main(int argc, char* argv[]) 
{
    ProgramController* app = new ProgramController(argc, argv);
    app->run();

    delete app;
    return 0;
}

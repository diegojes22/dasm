/*-- Librerias --*/
// De C++
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
// Librerias propias
#include "inputArgs.hpp"

using namespace std;

/*-- Constantes --*/
#define VERSION "0.0.1 ALPHA"

/*-- Prototipos de funcion --*/
void defineArgs(InputArgs *inArg);
void checkBasicFlags(InputArgs *inArg);
void correct_exit(InputArgs *inArg);
void failed_exit(InputArgs *inArg);

/*-- Main --*/
int main(int argc, char* argv[]) 
{
    InputArgs *inArg = new InputArgs(argc, argv);
    defineArgs(inArg);
    checkBasicFlags(inArg);

    delete inArg;
    return 0;
}

void defineArgs(InputArgs *inArg) 
{
    if(!inArg->checkArgsLen())
    {
        cout << "No se proporcionaron argumentos. Use --help para mas informacion." << endl;
        failed_exit(inArg);
    }

    inArg->addFlag("--help", "Despliega el menu de ayuda el cual describe cada argumento y el uso correcto del comando");
    inArg->addFlag("--version", "Muestra informacion adicional del programa");
    inArg->addArg("--file", "Archivo a crear . . ."); // Luego le pongo una buena descripcion.

    inArg->update();
}

void checkBasicFlags(InputArgs *inArg) 
{
    if(inArg->getFlag("--help")) 
    {
        cout << "dasm\n";
        inArg->printHelpOptions();
        correct_exit(inArg);
    }
    if(inArg->getFlag("--about")) 
    {
        cout << "dasm " << VERSION << endl;
        correct_exit(inArg);
    }

}

void correct_exit(InputArgs *inArg) {
    delete inArg;
    exit(0);
}

void failed_exit(InputArgs *inArg) {
    delete inArg;
    exit(1);
}

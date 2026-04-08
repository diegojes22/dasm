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

/*-- Main --*/
int main(int argc, char* argv[]) 
{
    InputArgs *inArg = new InputArgs(argc, argv);
    if(!inArg->checkArgsLen())
    {
        cout << "No se proporcionaron argumentos. Use --help para mas informacion." << endl;
        delete inArg;

        return 1;
    }

    bool help = inArg->flagExists("--help");
    bool version = inArg-> flagExists("--version");

    delete inArg;

    // Comprobar flags
    if(help)
    {
        cout << "dasm " << VERSION << endl;
        cout << "Uso: dasm [OPCIONES] <ARCHIVO>" << endl;
        cout << "OPCIONES:" << endl;
        cout << "  --help          Muestra esta ayuda." << endl;
        cout << "  --version       Muestra la version del programa." << endl;

        return 0;
    }

    if(version)
    {
        cout << "dasm " << VERSION << endl;
        return 0;
    }

    return 0;
}

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
    string file = getFlagValue(argc, argv, "--file");
    bool verbose = flagExists(argc, argv, "--verbose");

    if(file != NO_ARG) 
    {
        cout << "Valor del argumento --file: " << file << endl;
    } else {
        cout << "No se proporciono el argumento --file" << endl;
    }
    if(verbose)
    {
        cout << "Modo verboso activado! \n";
    }
    return 0;
}


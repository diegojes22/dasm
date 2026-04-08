#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#define NO_ARG ""

class InputArgs
{
private:
    int argc;
    std::vector<std::string> argv;
    
public:
    // Constructor
    InputArgs(int argc, char* argv[]);

    // Metodos
    std::string getFlagValue(std::string arg);
    bool flagExists(std::string arg);

    bool checkArgsLen();
};
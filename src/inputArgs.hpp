#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

#define NO_ARG ""

class InputArgs
{
private:
    int argc;
    std::vector<std::string> argv;

    std::vector<std::string> arguments;
    std::vector<std::string> flags;

    std::vector<std::string> arg_values;
    std::vector<bool> flags_values;

    std::vector<std::string> args_descriptions;
    std::vector<std::string> flags_descriptions;
    
public:
    // Constructor
    InputArgs(int argc, char* argv[]);

    // Metodos
    std::string getArgValue(std::string arg);
    bool flagExists(std::string arg);
    bool checkArgsLen();

    void addArg(std::string arg, std::string description);
    void addFlag(std::string flag, std::string description);
    std::string getArg(std::string arg);
    bool getFlag(std::string flag);

    void update();

    void printHelpOptions();
};
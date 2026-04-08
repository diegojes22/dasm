#include "inputArgs.hpp"

InputArgs::InputArgs(int argc, char* argv[]) {
    this->argc = argc;
    this->argv.assign(argv, argv + argc);
}

std::string InputArgs::getFlagValue(std::string arg)
{
    for (int i = 1; i < argc-1; i++) 
    {
        if(argv.at(i) == arg)
        {
            return argv[i + 1];
        }
    }

    return NO_ARG;
}

bool InputArgs::flagExists(std::string arg)
{
    for (int i = 1; i < argc; i++)
    {
        if(arg == argv[i])
        {
            return true;
        }
    }

    return false;
}

bool InputArgs::checkArgsLen()
{
    return argc > 1;
}
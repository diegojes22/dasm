#include "inputArgs.hpp"
#include "argsConf.cpp"

std::string getFlagValue(int argc, char* argv[], std::string arg)
{
    for (int i = 1; i < argc-1; i++) 
    {
        if(arg == argv[i])
        {
            return argv[i + 1];
        }
    }

    return NO_ARG;
}

bool flagExists(int argc, char* argv[], std::string arg)
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

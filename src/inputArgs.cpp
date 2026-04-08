#include "inputArgs.hpp"

InputArgs::InputArgs(int argc, char* argv[]) {
    this->argc = argc;
    this->argv.assign(argv, argv + argc);
}

std::string InputArgs::getArgValue(std::string arg)
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

void InputArgs::addArg(std::string arg, std::string description) 
{
    this->arguments.push_back(arg);
    this->args_descriptions.push_back(description);
    this->arg_values.push_back(NO_ARG);

    this->update();
}

void InputArgs::addFlag(std::string flag, std::string description)
{
    this->flags.push_back(flag);
    this->flags_descriptions.push_back(description);
    this->flags_values.push_back(false);

    this->update();
}

std::string InputArgs::getArg(std::string arg)
{
    auto it = std::find(arguments.begin(), arguments.end(), arg);
    if (it != arguments.end()) 
    {
        int index = std::distance(arguments.begin(), it);
        return arg_values.at(index);
    }
    return NO_ARG;
}

bool InputArgs::getFlag(std::string flag)
{
    for (size_t i = 0; i < flags.size(); i++)
    {
        if(flags.at(i) == flag)
        {
            return flags_values.at(i);
        }
    }
    return false;
}

void InputArgs::update()
{
    for (size_t i = 0; i < arguments.size(); i++)
    {
        arg_values.at(i) = getArgValue(arguments.at(i));
    }

    for (size_t i = 0; i < flags.size(); i++)
    {
        flags_values.at(i) = flagExists(flags.at(i));
    }
}

void InputArgs::printHelpOptions()
{
    std::cout << "Argumentos con parametros: \n";
    for (size_t i = 0; i < arguments.size(); i++) {
        std::cout << "\t" << arguments.at(i) << " : " << args_descriptions.at(i) << "\n";
    }

    std::cout << "\nArgumentos de bandera\n";
    for (size_t i = 0; i < flags.size(); i++) {
        std::cout << "\t" << flags.at(i) << " : " << flags_descriptions.at(i) << "\n";
    }
}
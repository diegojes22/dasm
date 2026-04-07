#pragma once

#include <iostream>
#include <string>

#define NO_ARG ""

std::string getFlagValue(int argc, char* argv[], std::string arg);
bool flagExists(int argc, char* argv[], std::string arg);
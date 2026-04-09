#include <iostream>
#include <fstream>

#ifndef ADMINFILE_HPP
#define ADMINFILE_HPP

class AdminFile 
{
private:
    std::string filepath;
    std::ofstream file;

public:
    AdminFile(std::string filepath);
    ~AdminFile();

    bool isOpen();
    void write(std::string txt);
};

#endif /* ADMINFILE_HPP */
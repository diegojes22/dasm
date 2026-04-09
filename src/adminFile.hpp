#include <iostream>
#include <fstream>
#include <dirent.h>

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

    bool loadTemplate(std::string template_name, std::string& template_content);
    std::string getTemplateList();
};

#endif /* ADMINFILE_HPP */
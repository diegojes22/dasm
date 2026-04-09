#include "adminFile.hpp"

/**
 * Constructor.
 * @param filepath Ruta del archivo a crear o abrir.
 */
AdminFile::AdminFile(std::string filepath)
{
    this->filepath = filepath;
    this->file.open(filepath);
} 

AdminFile::~AdminFile()
{
    if(this->file.is_open())
    {
        this->file.close();
    }
}

bool AdminFile::isOpen()
{
    return this->file.is_open();
}

void AdminFile::write(std::string txt)
{
    if(this->isOpen())
    {
        this->file << txt;
    }
}
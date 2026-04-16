#include <iostream>
#include <fstream>
#include <dirent.h>

#ifndef ADMINFILE_HPP
#define ADMINFILE_HPP

// Define este difectorio como una constante para que sea fácil de cambiar si es necesario.
// Aun no encuentro una forma de hacerlo dinámico, pero esto es suficiente por ahora
#define TEMPLATES_DIR "D:\\CodeProjects\\dasm\\src\\templates"

/** @brief 
 * Clase para administrar archivos 
 */
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
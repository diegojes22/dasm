#include "adminFile.hpp"

///
/// CONSTRUCTOR Y DESTRUCTOR
///
/**
 * Constructor.
 * @param filepath Ruta del archivo a crear o abrir.
 */
AdminFile::AdminFile(std::string filepath)
{
    this->filepath = filepath;
    this->file.open(filepath);
    std::cout << "Archivo abierto: " << filepath << "\n";
} 

/** Destructor de la clase: solo cierra archivos o stream abiertos */
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


bool AdminFile::loadTemplate(std::string template_name, std::string& template_content)
{
    std::string template_path = TEMPLATES_DIR "/" + template_name;
    std::cout << "Cargando plantilla: " << template_path << "\n";
    std::ifstream template_file(template_path);

    if(!template_file.is_open())
    {
        return false;
    }

    std::string line;
    template_content = "";

    while(std::getline(template_file, line))
    {
        template_content += line + "\n";
    }

    return true;
}

std::string AdminFile::getTemplateList()
{
    // Abrir el directorio de plantillas y listar los archivos disponibles
    DIR* dir = opendir(TEMPLATES_DIR);
    if(dir == nullptr) {
        std::cerr << "Error: No se pudo abrir el directorio de plantillas.\n";
        return "";
    }

    std::string template_list = "Plantillas disponibles:\n";

    struct dirent* input;

    while ((input = readdir(dir)) != nullptr) {
        std::string filename = input->d_name;
        if (filename != "." && filename != "..") {
            template_list += " - " + filename + "\n";
        }
    }
    
    closedir(dir);
    return template_list;
}
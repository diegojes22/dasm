#include "programController.hpp"

// Contructor y destructor
ProgramController::ProgramController(int argc, char* argv[])
{
    this->inputArgsHandler = new InputArgs(argc, argv);
    this->adminFileHandler = nullptr;
}

ProgramController::~ProgramController()
{
    if(this->inputArgsHandler != nullptr)
    {
        delete this->inputArgsHandler;
    }
    if(this->adminFileHandler != nullptr)
    {
        delete this->adminFileHandler;
    }
}

// Inicializadores basicos
/**
 * Inicializa los argumentos y flags que el programa acepta, junto con sus descripciones para el menu de ayuda.
 */
void ProgramController::initArgs()
{
    // Estas Flags de aqui son basicas, siempre se agregan al programa, sin importar los argumentos que se le pasen.
    this->inputArgsHandler->addFlag("--help", "Despliega el menu de ayuda el cual describe cada argumento y el uso correcto del comando");
    this->inputArgsHandler->addFlag("--version", "Muestra informacion adicional del programa");
    this->inputArgsHandler->addArg("--template", "Selecciona la plantilla a usar para generar el archivo de salida");
    // Esta flag es requerida si o si ya que es la que le indica al programa donde esta el archivo de entrada con la plantilla a transpilar.
    this->inputArgsHandler->addArg("--file", "*Archivo de entrada donde se declarar la plantilla (required)");
    // Parametros opcionales para armar el archivo de salida, si no se proporcionan se usaran los valores por defecto.
    this->inputArgsHandler->addArg("--header", "Codigo de encabezado a agregar al inicio del archivo de salida (default: vacio)");
    this->inputArgsHandler->addFlag("--endproc", "*Codigo de ensamblador a agregar al final del archivo de salida (default: codigo para terminar el programa)");
    this->inputArgsHandler->addFlag("--exclude-comments", "Excluye los comentarios de la plantilla en el archivo de salida");

    this->inputArgsHandler->update();
}

void ProgramController::checkBasicFlags()
{
    if(this->inputArgsHandler->getFlag("--help"))
    {
        std::cout << "dasm\n";
        this->inputArgsHandler->printHelpOptions();
        this->end_proc(0);
    }
    if(this->inputArgsHandler->getFlag("--version"))
    {
        std::cout << VERSION << "\n";
        this->end_proc(0);
    }
}

void ProgramController::checkArgs()
{
    if(!this->inputArgsHandler->checkArgsLen())
    {
        std::cerr << "No se proporcionaron argumentos. Use --help para mas informacion." << std::endl;
        this->end_proc(1);
    }
}

// Funciones de los argumentos
void ProgramController::fileHandlerFn()
{
    std::string filepath = this->inputArgsHandler->getArg("--file");
    if(filepath == NO_ARG)
    {
        std::cerr << "Error: No se proporciono un archivo de entrada. Use --help para mas informacion." << std::endl;
        this->end_proc(1);
    }

    this->adminFileHandler = new AdminFile(filepath);

    if(!this->adminFileHandler->isOpen())
    {
        std::cerr << "Error: No se pudo abrir el archivo proporcionado. Verifique la ruta e intente nuevamente." << std::endl;
        this->end_proc(1);
    }
}

void ProgramController::addHeaderFn()
{
    std::string header_type = this->inputArgsHandler->getArg("--header");
    if (header_type == "smallstack")
    {
        this->adminFileHandler->write(HEADER_SMALLSTACK_TASM);
    }
    else
    {
        // Agregar un header por defecto segun el tipo de plantilla que se este usando, por ahora solo hay una plantilla basica, pero en el futuro se pueden agregar mas plantillas y cada una puede tener un header diferente.
        this->adminFileHandler->write(BASIC_HEADER_TASM);
    }
}

void ProgramController::addEndProcFn()
{
    if(this->inputArgsHandler->getFlag("--endproc"))
    {
        this->adminFileHandler->write(END_PROC);
        this->adminFileHandler->write(BASIC_FOOTER_TASM);
    }
}

void ProgramController::checkTemplateFn()
{
    std::string template_name = this->inputArgsHandler->getArg("--template");
    if(template_name == NO_ARG) 
    {
        return;
    }
    else if(template_name == "list") 
    {
        std::cout << this->adminFileHandler->getTemplateList();
        this->end_proc(0);
    }

    std::string template_content = "";
    if(!this->adminFileHandler->loadTemplate(template_name, template_content))
    {
        std::cerr << "Error: No se pudo cargar la plantilla especificada. Verifique el nombre de la plantilla e intente nuevamente.\n";
        std::cout << this->adminFileHandler->getTemplateList();
        this->end_proc(1);
    }
    this->adminFileHandler->write(template_content);

    end_proc(0);
}

void ProgramController::addComentsFn()
{
    if(!this->inputArgsHandler->getFlag("--exclude-comments"))
    {
        this->adminFileHandler->write(CREDITS);
    }
}

// otros metodos
void ProgramController::end_proc(int code)
{
    if(code == 0)
    {
        std::cout << "\nPrograma terminado correctamente. \n";
    }
    else
    {
        std::cerr << "\nPrograma terminado con errores. \n";
    }
    // Liberar recursos y salir
    if(this->adminFileHandler != nullptr)
    {
        delete this->adminFileHandler;
    }
    if(this->inputArgsHandler != nullptr)
    {
        delete this->inputArgsHandler;
    }

    exit(code);
}

void ProgramController::run()
{
    std::cout << "Iniciando ejecucion del programa...\n";

    this->initArgs();
    this->checkBasicFlags();
    this->checkArgs();

    this->fileHandlerFn();
    this->checkTemplateFn();
    this->addHeaderFn();
    this->addEndProcFn();
}
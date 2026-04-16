#include "programController.hpp"


///
/// Constructor y destructor
///

/**
 * Constructor de la clase. Se recomienda crear la clase dentro de la funcion main
 * para inicializar los parametros.
 * @brief
 * 
 * El constructor recibe como entrada los argumentos de la terminal, argumentos que
 * se reciven en la funcion main de C/C++.
 * @param argc entero que cuenta el numero de parametros
 * @param argv arreglo de cadenas con los parametros introducidos de la terminal
 */
ProgramController::ProgramController(int argc, char* argv[])
{
    this->inputArgsHandler = new InputArgs(argc, argv);
    this->adminFileHandler = nullptr;
}

/**
 * Destructor: Solo libera la memoria reservada cuando la
 * clase es eliminada.
 */
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

///
/// Inicializadores basicos
///
/**
 * Inicializa los argumentos y flags que el programa acepta, junto con sus descripciones 
 * para el menu de ayuda.
 */
void ProgramController::initArgs()
{
    /*
     USO:
        Dentro de esta funcion define los argumentos que el programa recibira desde la terminal.
        A la hora de definir sun argumento debes declarar de que tipo, el nombre del argumento,
        y una descripcion del mismo. Todo esto tambien ayudara cuando se desee desplegar el menu
        de ayuda.
    */
    
    /* 
      Las flags que estan aqui son de un unico uso, es decir, si se llaman solo se realiza esa tarea y el programa cierra.
      Ejemplo de lo anterior son los parametros --help o --version (estos dos parametros son llamados checkBasicFlags y se
      mandan llamar en la funcion con el mismo nombre).
     */
    this->inputArgsHandler->addFlag("--help", "Despliega el menu de ayuda el cual describe cada argumento y el uso correcto del comando");
    this->inputArgsHandler->addFlag("--version", "Muestra informacion adicional del programa");
    this->inputArgsHandler->addFlag("--about", "?");
    this->inputArgsHandler->addArg("--template", "Selecciona la plantilla a usar para generar el archivo de salida. --template [list] | <template_name.asm>");

    // Esta flag es requerida si o si ya que es la que le indica al programa donde esta el archivo de entrada con la plantilla a transpilar.
    this->inputArgsHandler->addArg("file", "*Archivo de entrada donde se declarar la plantilla (required). file <file_output>");
    // Parametros opcionales para armar el archivo de salida, si no se proporcionan se usaran los valores por defecto.
    this->inputArgsHandler->addArg("--header", "Codigo de encabezado a agregar al inicio del archivo de salida (default: vacio). --header <default | smallstack>");
    this->inputArgsHandler->addFlag("--endproc", "*Codigo de ensamblador a agregar al final del archivo de salida (default: codigo para terminar el programa)");
    this->inputArgsHandler->addFlag("--exclude-comments", "Excluye los comentarios de la plantilla en el archivo de salida");
    this->inputArgsHandler->addArg("--add-variables", "Agrega variables predefinidas al archivo de salida (default: no se agregan variables). --add-variables <default | [custom]>");
    this->inputArgsHandler->addFlag("--init-ds", "Agrega el segmento de codigo para inicializar el segmento de datos al archivo de salida");

    this->inputArgsHandler->update();
}

/**
 * En esta funcion comprobamos si se ingresaron las Basic Flags, es decir,
 * si el usuario ingreso algo como --help o --version, solo ejecutaremos 
 * la funcion correspondiente y el programa terminara.
 */
void ProgramController::checkBasicFlags()
{
    // Invocar la funcion para la ayuda
    if(this->inputArgsHandler->getFlag("--help"))
    {
        std::cout << "dasm\n";
        this->inputArgsHandler->printHelpOptions();
        this->end_proc(0);
    }
    // Invocar funcion para mostrar la version
    if(this->inputArgsHandler->getFlag("--version"))
    {
        std::cout << VERSION << "\n";
        this->end_proc(0);
    }
    // Invocar funcion para mostrar la animacion de about
    if(this->inputArgsHandler->getFlag("--about"))
    {
        about about_obj;
        about_obj.invoqueAnimation();
        about_obj.showAboutInfo();
        this->end_proc(0);
    }
}

/**
 * Esta funcion solo verifica que se haya ingresado al menos un argumento,
 * de lo contrario, si la funcion no detecta lo anterior causara que el programa
 * finalice con error.
 */
void ProgramController::checkArgs()
{
    if(!this->inputArgsHandler->checkArgsLen())
    {
        std::cerr << "No se proporcionaron argumentos. Use --help para mas informacion." << std::endl;
        this->end_proc(1);
    }
}

///
/// FUNCIONES PROPIAS
/// En la siguiente seccion de codigo define tus funciones de acuerdo con los
/// argumentos declarardos en la funcion `initArgs()`.
/// Estas funciones deben declararse dentro de la clase en el archivo `programController.hpp`
/// y se recomienda escribirlas en el orden de como fueron declaradas en el archivo ya mencionado.
///

/**
 * Verifica que el argumento file sea ingresado, ademas de que se encarga
 * de abrir el archivo ingresado para comenzar a trabajar con el.
 * Esta funcion es de una prioridad alta, por lo que en el metodo run estara
 * muy arriba.
 */
void ProgramController::fileHandlerFn()
{
    std::string filepath = this->inputArgsHandler->getArg("file");
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

/**
 * Argumento para agregar un header u otro en el archivo seleccionado.
 * Los valores en cuestion son:
 *  - smalstack: pila de 0050h
 *  - <default>: si no hay valor o este no coincide, se agrega una pila de 0100h
 */
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

/**
 * Argumento para agregar el codigo de salida de TASM al final del archivo.
 */
void ProgramController::addEndProcFn()
{
    if(this->inputArgsHandler->getFlag("--endproc"))
    {
        this->adminFileHandler->write(END_PROC);
        this->adminFileHandler->write(BASIC_FOOTER_TASM);
    }
}

/**
 * Se encraga de gestionar las plantillas ya existentes para cargarlas
 * en el archivo de salida.
 */
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

/**
 * Funcion para verificar el argumento --exclude-comments.
 * El archivo generado por defecto tiene comentarios en el inicio los cuales
 * corresponden a los creditos del autor (yo), pero se pueden desactivar con este argumento. 
 */
void ProgramController::addComentsFn()
{
    if(!this->inputArgsHandler->getFlag("--exclude-comments"))
    {
        this->adminFileHandler->write(CREDITS);
    }
}

void ProgramController::addVariablesFn()
{
    std::string add_variables = this->inputArgsHandler->getArg("--add-variables");
    if(add_variables == NO_ARG)
    {
        return;
    }
    else if(add_variables == "default")
    {
        this->adminFileHandler->write("\tdb text \"Hello, World!\" 0Dh,0Ah \n");
    }
    else
    {
        this->adminFileHandler->write("\t; Variables personalizadas\n");
        this->adminFileHandler->write("\tdb "+add_variables+" 48 \n");
    }

}

void ProgramController::addMainTasmFn()
{
    this->adminFileHandler->write(MAIN_TASM_HEADER);
}

void ProgramController::initDSFn()
{
    if(this->inputArgsHandler->getFlag("--init-ds"))
    {
        this->adminFileHandler->write(INIT_DS_TASM);
    }
}


///
/// Otras funciones
///
/**
 * Esta funcion se usa principalmente en flags basicas o de un solo uso para
 * terminar el programa sin necesidad del return en la funcion main.
 */
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

/** 
 * Funcion de ejecucion.
 * 
 * Dentro de esta funcio manda llamar tus funciones definidas de acuerdo a los parametros declarados.
 * Es muy importante mantener una prioridad debido a la ejecucion secuencial de las mismas.
 * Mientras mas arriba este una funcion, mas prioridad tendra, Tenlo en cuenta!.
 */
void ProgramController::run()
{
    this->initArgs();
    this->checkBasicFlags();
    this->checkArgs();

    this->fileHandlerFn();
    this->checkTemplateFn();
    this->addComentsFn();
    this->addHeaderFn();
    this->addVariablesFn();
    this->addMainTasmFn();
    this->initDSFn();
    this->addEndProcFn();
}
#include "inputArgs.hpp"
#include "adminFile.hpp"
#include "asmControll.hpp"

#ifndef PROGRAMCONTROLLER_HPP
#define PROGRAMCONTROLLER_HPP

#define VERSION "0.0.1 ALPHA"

class ProgramController
{
private:
    InputArgs* inputArgsHandler;
    AdminFile* adminFileHandler;

public:
    // Contructor y destructor
    ProgramController(int argc, char* argv[]);    
    ~ProgramController();

    // Inicializadores basicos
    void initArgs();
    void checkBasicFlags();
    void checkArgs();

    // Funciones de los argumentos
    void fileHandlerFn();
    void checkTemplateFn();
    void addComentsFn();
    void addHeaderFn();
    void addEndProcFn();

    // otros metodos
    void end_proc(int code);
    void run();
};

#endif
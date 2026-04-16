#include "inputArgs.hpp"
#include "adminFile.hpp"
#include "asmControll.hpp"
#include "about.hpp"

#ifndef PROGRAMCONTROLLER_HPP
#define PROGRAMCONTROLLER_HPP

#define VERSION "0.1.3 ALPHA"

/**
 * Control y manejo general del comando
 */
class ProgramController
{
private:
    InputArgs* inputArgsHandler;
    AdminFile* adminFileHandler;

public:
    //
    // Contructor y destructor
    //
    ProgramController(int argc, char* argv[]);    
    ~ProgramController();

    //
    // Inicializadores basicos
    // Estas funciones se encargan de realizar validaciones como: la sintaxis del comando,
    // argumentos de bandera de un solo uso (como --version o --help), etc . . .
    //
    void initArgs();
    void checkBasicFlags();
    void checkArgs();

    //
    // Funciones de los argumentos.
    // Estas son funciones que corresponden con el control y manejo del programa de acuerdo a
    // los argumentos ingresados en el comando
    //
    /* Define tus funciones a partir de aqui */
    void fileHandlerFn();
    void checkTemplateFn();
    void addComentsFn();
    void addHeaderFn();
    void addVariablesFn();
    void addMainTasmFn();
    void initDSFn();
    void addEndProcFn();

    //
    // otros metodos
    //
    void end_proc(int code);
    void run();
};

#endif
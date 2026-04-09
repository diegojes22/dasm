#include <iostream>
#include <string>

#ifndef ASMCONTROL_HPP
#define ASMCONTROL_HPP

const std::string CREDITS = R"(
; Plantilla de Turbo Assembler generada por dasm
; Creador: @diegojes22
; 
; Puedes revisar el proyecto en GitHub para cambiar las opciones de compilacion,
; agregar plantillas, colaborar, aportar, hacer un fork o simplemente para ver el codigo fuente:
;   https://github.com/diegojes22/dasm
;
)";

const std::string BASIC_HEADER_TASM = R"(
.model small
.stack 100h
.data
.code
)";

const std::string HEADER_SMALLSTACK_TASM = R"(
.model small
.stack 50h
.data
    ; Declarar variables y constantes aqui
.code
)";

const std::string BASIC_FOOTER_TASM = R"(
end main
)";

const std::string END_PROC = R"(
    ; Terminar programa
    end_proc_asm:
        mov ax, 4C00h
        int 21h
)";

#endif
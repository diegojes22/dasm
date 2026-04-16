# DASM - Turbo Assembler Generator

[![Version](https://img.shields.io/badge/version-0.0.1-blue.svg)](https://github.com/diegojes22/dasm)
[![Status](https://img.shields.io/badge/status-ALPHA-orange.svg)]()
[![Language](https://img.shields.io/badge/language-C%2B%2B-red.svg)]()
[![Compiler](https://img.shields.io/badge/compiler-g%2B%2B-brightgreen.svg)]()
[![License](https://img.shields.io/badge/license-GPL3.0-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows-blue.svg)]()

---

## Descripción

**DASM** es una herramienta generadora de scripts base para **Turbo Ensamblador (TASM)**. El proyecto fue desarrollado como trabajo para la clase de Lenguajes de Interfaz y permite crear archivos de ensamblador con plantillas predefinidas y configuraciones personalizables.

**Creador:** @diegojes22  
**Repositorio:** https://github.com/diegojes22/dasm

---

## Características Principales

- Generación de plantillas base de TASM desde línea de comandos
- Argumentos y flags configurables
- Gestión automática de archivos de ensamblador
- Plantillas predefinidas personalizables
- Encabezados y créditos automáticos
- Interfaz por argumentos CLI

---

## Estructura del Proyecto

```
ASM Transpiler/
├── build.ps1                 # Script de compilación (PowerShell)
├── comandos.md               # Información de comandos
├── LICENSE                   # Licencia del proyecto
├── README.md                 # Este archivo
├── out/                      # Carpeta de salida (ejecutables)
└── src/                      # Código fuente
    ├── dasm.cpp              # Punto de entrada principal
    ├── programController.cpp  # Controlador del programa
    ├── programController.hpp  # Header del controlador
    ├── inputArgs.cpp         # Procesador de argumentos
    ├── inputArgs.hpp         # Header de argumentos
    ├── adminFile.cpp         # Gestor de archivos
    ├── adminFile.hpp         # Header del gestor
    ├── asmControll.hpp       # Constantes y plantillas de ensamblador
    └── templates/            # Plantillas de código ensamblador
        ├── abc.asm
        └── print_message.asm
```

---

## Componentes Principales

### ProgramController (programController.hpp/cpp)

Controlador principal del programa que orquesta:
- Inicialización de argumentos
- Validación de flags y argumentos
- Procesamiento de funcionalidades
- Manejo de archivos
- Control de plantillas

**Métodos principales:**
- `initArgs()` - Inicializa los argumentos del programa
- `checkBasicFlags()` - Valida flags básicos
- `checkArgs()` - Valida argumentos
- `fileHandlerFn()` - Maneja operaciones de archivo
- `checkTemplateFn()` - Controla plantillas
- `addComentsFn()` - Añade comentarios
- `addHeaderFn()` - Añade encabezado
- `addEndProcFn()` - Añade procedimiento final

### InputArgs (inputArgs.hpp/cpp)

Procesador de argumentos de línea de comandos:
- Gestiona argumentos positivos
- Gestiona flags (banderas)
- Almacena descripciones
- Valida entrada del usuario

**Métodos principales:**
- `addArg()` - Agrega un argumento
- `addFlag()` - Agrega un flag
- `getArg()` / `getArgValue()` - Obtiene valor de argumento
- `getFlag()` / `flagExists()` - Verifica flags
- `printHelpOptions()` - Muestra opciones de ayuda

### AdminFile (adminFile.hpp/cpp)

Gestor de archivos:
- Crea y escribe archivos de salida
- Carga plantillas desde la carpeta `templates/`
- Enumera plantillas disponibles

**Métodos principales:**
- `write()` - Escribe contenido en archivo
- `loadTemplate()` - Carga una plantilla
- `getTemplateList()` - Lista plantillas disponibles
- `isOpen()` - Verifica si archivo está abierto

### ASM Control (asmControll.hpp)

Define constantes y plantillas:
- `CREDITS` - Créditos de la herramienta
- `BASIC_HEADER_TASM` - Encabezado básico de TASM
- `HEADER_SMALLSTACK_TASM` - Encabezado con stack reducido
- `BASIC_FOOTER_TASM` - Pie de página básico
- `END_PROC` - Procedimiento de finalización

---

## Compilación y Ejecución

> Para que la compilacion funcione debes tener instalado g++ (GCC) y PowerShell en tu sistema Windows. Asegúrate de tenerlos configurados correctamente en tu PATH.
> 
> Ademas, dentro del directorio del proyecto crea una carpeta llamada `out` para almacenar el ejecutable generado.

### Compilar el proyecto

**Opción 1 (Automática con PowerShell):**
```powershell
.\build.ps1
```

**Opción 2 (Manual):**
```powershell
g++ ./src/dasm.cpp ./src/inputArgs.cpp ./src/adminFile.cpp ./src/programController.cpp -o ./out/dasm.exe
```

### Ejecutar el programa

```powershell
./out/dasm <argumentos>
```

Ver ayuda:
```powershell
./out/dasm --help
```

---

## Flujo de Ejecución

```
dasm.exe (main)
    ↓
ProgramController::run()
    ↓
├─ initArgs()          → Inicializa argumentos del usuario
├─ checkBasicFlags()   → Valida flags básicos (--help, --version)
├─ checkArgs()         → Valida argumentos requeridos
    ↓
├─ fileHandlerFn()     → Crea archivo de salida
├─ checkTemplateFn()   → Selecciona plantilla
├─ addHeaderFn()       → Añade encabezado
├─ addComentsFn()      → Añade comentarios
├─ addEndProcFn()      → Añade procedimiento final
    ↓
└─ end_proc()          → Finaliza con código de salida
```

---

## Ejemplos de Uso

Generar un archivo de ensamblador básico:
```powershell
./out/dasm --output programa.asm --template abc
```

Con comentarios y encabezado personalizado:
```powershell
./out/dasm --output programa.asm --template print_message --comments --header
```

---

## Tecnologías Utilizadas

| Aspecto | Tecnología |
|--------|-----------|
| Lenguaje | C++ |
| Compilador | g++ (GCC) |
| Sistema operativo | Windows |
| Lenguaje objetivo | Turbo Assembler (TASM) |
| Scripts de compilación | PowerShell |

---

## Notas Adicionales

- El proyecto está en fase ALPHA (v0.0.1), por lo que puede estar sujeto a cambios significativos
- Las plantillas se encuentran en la carpeta `src/templates/`
- Se pueden agregar nuevas plantillas sin necesidad de modificar el código compilado
- El programa genera comentarios de atribución automáticos al inicio de cada archivo generado

---

## Enlaces Útiles

- **GitHub del proyecto:** https://github.com/diegojes22/dasm
- **Turbo Assembler (TASM):** Referencia histórica de ensamblador x86

---

**Última actualización:** Abril 2026
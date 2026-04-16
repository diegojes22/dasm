#include "about.hpp"

namespace animation
{
// Frames de la animacion tipo CLI moderna
const std::string frame_1 = R"(
    [.] Cargando modulos
)";

const std::string frame_2 = R"(
    [o] Cargando modulos
)";

const std::string frame_3 = R"(
    [O] Cargando modulos
)";

const std::string frame_4 = R"(
    [o] Cargando modulos
)";

const std::string welcome = R"(
+----------------------------------------------------------+
|                                                          |
|  DASM - Dissassembly Assistant & Simulator Module        |
|                                                          |
+----------------------------------------------------------+
)";

const std::string processing = R"(
  [*] Inicializando entorno CLI...
)";

const std::string complete = R"(
  [OK] Sistema listo.
)";

}

/////////////////////////
/* Implementacion de la clase about */

void about::invoqueAnimation()
{
    // Limpia la pantalla
    system("cls");
    
    // Muestra el banner de bienvenida
    std::cout << animation::welcome << std::endl;
    Sleep(800);
    
    // Animacion de carga en una sola linea (estilo CLI)
    std::cout << animation::frame_1 << "\r" << std::flush;
    Sleep(220);
    std::cout << animation::frame_2 << "\r" << std::flush;
    Sleep(220);
    std::cout << animation::frame_3 << "\r" << std::flush;
    Sleep(220);
    std::cout << animation::frame_4 << "\r" << std::flush;
    Sleep(220);
    std::cout << "                                   \r";
    
    // Muestra el procesamiento
    std::cout << animation::processing << std::endl;
    Sleep(600);
    std::cout << "\r" << animation::complete << std::endl;
    Sleep(500);
}

void about::showAboutInfo()
{
    system("cls");
    
    std::cout << R"(
+-----------------------------------------------------------------+
|                                                                 |
|                   DASM CLI - ABOUT THIS TOOL                   |
|                                                                 |
+-----------------------------------------------------------------+

> VERSION
  0.1.3 ALPHA

> DESCRIPCION
  DASM es una herramienta educativa diseñada para facilitar el
  trabajo con plantillas de ensamblador x86/TASM desde linea de
  comandos. Su enfoque es rapido, simple y didactico.

> CARACTERISTICAS
  - Interfaz CLI por argumentos
  - Generacion de archivos .asm desde plantillas
  - Listado y carga de templates desde src/templates
  - Insercion de header, comentarios y finalizacion opcional
  - Flujo pensado para automatizacion en terminal

> AUTOR
  Diego Jesus (diegojes22)

> LICENCIA
  GNU AGPLv3

> COMANDOS DISPONIBLES
  -h, --help           Muestra esta ayuda
  -v, --version        Muestra la version
  --about              Muestra informacion detallada
  file <archivo>        Archivo de salida requerido
  --template <name>     Carga una plantilla .asm
  --template list       Muestra plantillas disponibles
  --header <default|smallstack>
  --endproc             Agrega bloque de finalizacion
  --exclude-comments    Omite comentarios de creditos
  --add-variables <default|custom>
  --init-ds             Inicializa el segmento DS

> EJEMPLOS DE USO
  dasm --help
  dasm --about
  dasm salida.asm --template list
  dasm salida.asm --template abc.asm --header smallstack --endproc

> PARA MAS INFORMACION
  Repositorio: https://github.com/diegojes22/dasm

)" << std::endl;
}
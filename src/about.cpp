#include "about.hpp"


namespace face
{
const std::string sleep_1 = R"(


   z
    ────  ────

      █
)";

const std::string sleep_2 = R"(

  z
   z
    ────  ────

      ▀
)";

const std::string sleep_3 = R"(
 z
  z
   z
    ────  ────

      █
)";

const std::string wake = R"(



    ────  ────

      ▀
)";

const std::string wake_up = R"(



    ███   ███
    
       ──
)";

const std::string activating = R"(



    ────  ────

        ██
)";

const std::string smile = R"(



    ███   ███
    
      ╰──╯
)";

}

/////////////////////////
/* Implementacion de la clase about */
void about::invoqueAnimation()
{
    std::cout << face::sleep_1 << std::endl;
    Sleep(500);
    std::cout << face::sleep_2 << std::endl;
    Sleep(500);
    std::cout << face::sleep_3 << std::endl;
    Sleep(500);
    std::cout << face::wake << std::endl;
    Sleep(500);
    std::cout << face::wake_up << std::endl;
    Sleep(500);
    std::cout << face::activating << std::endl;
    Sleep(500);
    std::cout << face::smile << std::endl;
}
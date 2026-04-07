#include "screen.hpp"

int main(int argc, char* argv[]) {
    clearScreen();
    gotoxy(10, 5);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
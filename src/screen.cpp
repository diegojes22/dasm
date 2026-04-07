#include "screen.hpp"

void gotoxy(int x, int y) {
    std::cout << "\033[" << y + 1 << ";" << x + 1 << "H";
}

void clearScreen() {
    std::cout << "\033[2J";
    gotoxy(0, 0);
}
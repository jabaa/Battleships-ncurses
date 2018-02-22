#include "Battleships.h"
#include "utils.h"
#include <ncurses.h>
#include <iostream>

int main() {
    try {
        ts::Battleships bs;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

#include "Battleships.h"
#include "utils.h"
#include <stdexcept>

namespace ts {

bool Battleships::initialized = false;

Battleships::Battleships() {
    if (initialized) {
        throw std::logic_error("Only one instance of class Battleships allowed");
    }
    initialized = true;
    initscr();

    drawTitle();
}

Battleships::~Battleships() {
    initialized = false;
    endwin();
}

void Battleships::drawTitle() {
    curs_set(0);
    drawText(2, 10, "BATTLESHIPS");
    getch();
}

}

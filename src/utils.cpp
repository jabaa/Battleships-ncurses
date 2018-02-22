#include "utils.h"

#define CHAR_WIDHT 3
#define CHAR_HEIGHT 5
#define SYMBOL "#"
#define VERTICAL_SPACE 1
#define HORIZONTAL_SPACE 1

namespace ts {

void drawText(std::size_t y, std::size_t x, std::string text) {
    std::size_t currentX(x);
    std::size_t currentY(y);

    for (auto c : text) {
        if (c == '\n') {
            currentX = x;
            currentY = currentY + CHAR_HEIGHT + HORIZONTAL_SPACE;
            continue;
        }
        drawCharacter(currentY, currentX, c);
        currentX += CHAR_WIDHT + VERTICAL_SPACE;
    }
}

void drawCharacter(std::size_t y, std::size_t x, char c) {
    switch(c) {
        case 'A':
            for (std::size_t i = x; i <= x + 2; i += 2) {
                for (std::size_t j = y + 1; j <= y + 4; ++j)
                mvprintw(j, i, SYMBOL);
            }
            mvprintw(y, x + 1, SYMBOL);
            mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'B':
            for (std::size_t i = y; i <= y + 4; ++i) {
                mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = y; i <= y + 4; i += 2) {
                mvprintw(i, x + 1, SYMBOL);
            }
            for (std::size_t i = y + 1; i <= y + 3; i += 2) {
                mvprintw(i, x + 2, SYMBOL);
            }
            break;
        case 'E':
            for (std::size_t i = y; i <= y + 4; ++i) {
                mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = x + 1; i <= x + 2; ++i) {
                for (std::size_t j = y; j <= y + 4; j += 2) {
                    mvprintw(j, i, SYMBOL);
                }
            }
            break;
        case 'H':
            for (std::size_t i = x; i <= x + 2; i += 2) {
                for (std::size_t j = y; j <= y + 4; ++j) {
                    mvprintw(j, i, SYMBOL);
                }
            }
            mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'I':
            for (std::size_t j = y; j <= y + 4; ++j) {
                mvprintw(j, x + 1, SYMBOL);
            }
            break;
        case 'L':
            for (std::size_t i = y; i <= y + 4; ++i) {
                mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 2; ++i) {
                mvprintw(y + 4, i, SYMBOL);
            }
            break;
        case 'P':
            for (std::size_t i = y; i <= y + 4; ++i) {
                mvprintw(i, x, SYMBOL);
            }
            mvprintw(y, x + 1, SYMBOL);
            mvprintw(y + 1, x + 2, SYMBOL);
            mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'S':
            for (std::size_t i = x + 1; i <= x + 2; ++i) {
                mvprintw(y, i, SYMBOL);
            }
            for (std::size_t i = 0; i <= 2; ++i) {
                mvprintw(y + 1 + i, x + i, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 1; ++i) {
                mvprintw(y + 4, i, SYMBOL);
            }
            break;
        case 'T':
            for (std::size_t i = y; i <= y + 4; ++i) {
                mvprintw(i, x + 1, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 2; i += 2) {
                mvprintw(y, i, SYMBOL);
            }
            break;
    }
}

}

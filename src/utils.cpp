#include "utils.h"
#include "Ncurses.h"

constexpr std::size_t CHAR_WIDHT(3);
constexpr std::size_t CHAR_HEIGHT(5);
constexpr char SYMBOL('#');
constexpr std::size_t VERTICAL_SPACE(1);
constexpr std::size_t HORIZONTAL_SPACE(1);

namespace ts {

void drawBigText(std::size_t y, std::size_t x, std::string text) {
    std::size_t currentX(x);
    std::size_t currentY(y);

    for (auto c : text) {
        if (c == '\n') {
            currentX = x;
            currentY = currentY + CHAR_HEIGHT + HORIZONTAL_SPACE;
            continue;
        }
        drawBigCharacter(currentY, currentX, c);
        currentX += CHAR_WIDHT + VERTICAL_SPACE;
    }
}

void drawBigCharacter(std::size_t y, std::size_t x, char c) {
    switch(c) {
        case 'A':
            for (std::size_t i = x; i <= x + 2; i += 2) {
                for (std::size_t j = y + 1; j <= y + 4; ++j) {
                    ts::Ncurses::mvprintw(j, i, SYMBOL);
                }
            }
            ts::Ncurses::mvprintw(y, x + 1, SYMBOL);
            ts::Ncurses::mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'B':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ncurses::mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = y; i <= y + 4; i += 2) {
                ts::Ncurses::mvprintw(i, x + 1, SYMBOL);
            }
            for (std::size_t i = y + 1; i <= y + 3; i += 2) {
                ts::Ncurses::mvprintw(i, x + 2, SYMBOL);
            }
            break;
        case 'E':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ncurses::mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = x + 1; i <= x + 2; ++i) {
                for (std::size_t j = y; j <= y + 4; j += 2) {
                    ts::Ncurses::mvprintw(j, i, SYMBOL);
                }
            }
            break;
        case 'H':
            for (std::size_t i = x; i <= x + 2; i += 2) {
                for (std::size_t j = y; j <= y + 4; ++j) {
                    ts::Ncurses::mvprintw(j, i, SYMBOL);
                }
            }
            ts::Ncurses::mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'I':
            for (std::size_t j = y; j <= y + 4; ++j) {
                ts::Ncurses::mvprintw(j, x + 1, SYMBOL);
            }
            break;
        case 'L':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ncurses::mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 2; ++i) {
                ts::Ncurses::mvprintw(y + 4, i, SYMBOL);
            }
            break;
        case 'P':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ncurses::mvprintw(i, x, SYMBOL);
            }
            ts::Ncurses::mvprintw(y, x + 1, SYMBOL);
            ts::Ncurses::mvprintw(y + 1, x + 2, SYMBOL);
            ts::Ncurses::mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'S':
            for (std::size_t i = x + 1; i <= x + 2; ++i) {
                ts::Ncurses::mvprintw(y, i, SYMBOL);
            }
            for (std::size_t i = 0; i <= 2; ++i) {
                ts::Ncurses::mvprintw(y + 1 + i, x + i, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 1; ++i) {
                ts::Ncurses::mvprintw(y + 4, i, SYMBOL);
            }
            break;
        case 'T':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ncurses::mvprintw(i, x + 1, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 2; i += 2) {
                ts::Ncurses::mvprintw(y, i, SYMBOL);
            }
            break;
        default:
            break;
    }
}

} // namespace ts

#include "Ncurses.h"
#include <curses.h>
#include <sstream>

namespace ts {
namespace Ui {
namespace Ncurses {

int Ncurses::LINES;
int Ncurses::COLS;

void Ncurses::curs_set(bool isSet) {
    ::curs_set(static_cast<int>(isSet));
}

void Ncurses::endwin() {
    ::endwin();
}

void Ncurses::initscr() {
    ::initscr();
    LINES = ::LINES;
    COLS = ::COLS;
}

void Ncurses::mvprintw(std::size_t y, std::size_t x, const char c) {
    ::mvprintw(static_cast<int>(y), static_cast<int>(x), &c);
}

void Ncurses::mvprintw(std::size_t y, std::size_t x, const std::string& str) {
    ::mvprintw(static_cast<int>(y), static_cast<int>(x), str.c_str());
}

#pragma push_macro("getch")
#undef getch
char Ncurses::getch() {
#pragma pop_macro("getch")
    return ::getch();
}

void Ncurses::clear() {
    ::clear();
}

void Ncurses::noecho() {
    ::noecho();
}

void Ncurses::refresh() {
    ::refresh();
}

} // namespace Ncurses
} // namespace Ui
} // namespace ts

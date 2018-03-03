#include "Ncurses.h"
#include <curses.h>

namespace ts {

void Ncurses::mvprintw(std::size_t y, std::size_t x, const char& c) {
    ::mvprintw(static_cast<int>(y), static_cast<int>(x), &c);
}

void Ncurses::mvprintw(std::size_t y, std::size_t x, const std::string& str) {
    ::mvprintw(static_cast<int>(y), static_cast<int>(x), str.c_str());
}

void ts::Ncurses::initscr() {
    ::initscr();
}

void ts::Ncurses::endwin() {
    ::endwin();
}

void ts::Ncurses::curs_set(bool isSet) {
    ::curs_set(static_cast<int>(isSet));
}

#define getch_tmp_asdfj23sdlkfj5gds() getch()
#undef getch
char ts::Ncurses::getch() {
#define getch() getch_tmp_asdfj23sdlkfj5gds()
#undef getch_tmp
    return ::getch();
}

void ts::Ncurses::clear() {
    ::clear();
}

void ts::Ncurses::noecho() {
    ::noecho();
}

} // namespace ts

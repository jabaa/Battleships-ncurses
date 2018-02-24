#include "Ncurses.h"

namespace ts {

void Ncurses::mvprintw(std::size_t y, std::size_t x, const char& c) {
    ::mvprintw(static_cast<int>(y), static_cast<int>(x), &c);
}

void Ncurses::mvprintw(std::size_t y, std::size_t x, const std::string& str) {
    ::mvprintw(static_cast<int>(y), static_cast<int>(x), str.c_str());
}

} // namespace ts

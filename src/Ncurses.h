#ifndef BATTLESHIPS_NCURSES_H
#define BATTLESHIPS_NCURSES_H

#include <string>
#include <ncurses.h>

namespace ts {

class Ncurses {
public:
    static void mvprintw(std::size_t y, std::size_t x, const char& c);
    static void mvprintw(std::size_t y, std::size_t x, const std::string& str);
};

} // namespace ts

#endif // BATTLESHIPS_NCURSES_H

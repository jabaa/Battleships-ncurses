#ifndef BATTLESHIPS_NCURSES_H
#define BATTLESHIPS_NCURSES_H

#include <string>

namespace ts {

class Ncurses {
public:
    static void mvprintw(std::size_t y, std::size_t x, const char& c);
    static void mvprintw(std::size_t y, std::size_t x, const std::string& str);
    static void initscr();
    static void endwin();
    static void curs_set(bool isSet);
    static char getch();
    static void clear();
    static void noecho();
};

} // namespace ts

#endif // BATTLESHIPS_NCURSES_H

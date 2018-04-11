#ifndef BATTLESHIPS_NCURSES_H
#define BATTLESHIPS_NCURSES_H

#include <string>

namespace ts {
namespace Ui {
namespace Ncurses {

class Ncurses {
public:
    static int LINES;
    static int COLS;

    static void clear();
    static void curs_set(bool isSet);
    static void endwin();
    static char getch();
    static void initscr();
    static void mvprintw(std::size_t y, std::size_t x, const char c);
    static void mvprintw(std::size_t y, std::size_t x, const std::string& str);
    static void noecho();
    static void refresh();
};

} // namespace Ncurses
} // namespace Ui
} // namespace ts

#endif // BATTLESHIPS_NCURSES_H

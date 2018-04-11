#include "Ui/Ncurses/Game.h"
#include "Ui/Ncurses/Ncurses.h"

namespace ts {
namespace Ui {
namespace Ncurses {

void Game::drawField(std::size_t y, std::size_t x) {
    for (char i = 0; i < 9; ++i) {
        ts::Ui::Ncurses::Ncurses::mvprintw(y, x + 2 + 2*i, '1' + i);
        ts::Ui::Ncurses::Ncurses::mvprintw(y + 2 + 2*i, x, 'a' + i);
        for (char j = 0; j < 9; ++j) {
            ts::Ui::Ncurses::Ncurses::mvprintw(y + 2 + 2*i, x + 2 + 2*j, 'O');
        }
    }
    ts::Ui::Ncurses::Ncurses::getch();
}

void Game::drawShiplist(std::size_t y, std::size_t x) {
    for (char i = 0; i < 9; ++i) {
        ts::Ui::Ncurses::Ncurses::mvprintw(y, x + 2 + 2*i, '1' + i);
        ts::Ui::Ncurses::Ncurses::mvprintw(y + 2 + 2*i, x, 'a' + i);
        for (char j = 0; j < 9; ++j) {
            ts::Ui::Ncurses::Ncurses::mvprintw(y + 2 + 2*i, x + 2 + 2*j, 'O');
        }
    }
    ts::Ui::Ncurses::Ncurses::getch();
}

} // namespace Ncurses
} // namespace Ui
} // namespace ts
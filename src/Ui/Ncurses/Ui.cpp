#include "Ui/Ncurses/LocalGame.h"
#include "Ui/Ncurses/Ncurses.h"
#include "Ui/Ncurses/Ui.h"
#include <stdexcept>

constexpr std::size_t CHAR_WIDHT(3);
constexpr std::size_t CHAR_HEIGHT(5);
constexpr char SYMBOL('#');
constexpr std::size_t VERTICAL_SPACE(2);
constexpr std::size_t HORIZONTAL_SPACE(2);

namespace ts {
namespace Ui {
namespace Ncurses {

bool Ui::screenInitialized = false;

Ui::Ui() : state(State::INTRO) {}

int Ui::exec() {
    if (screenInitialized) {
        throw std::logic_error("Only one instance of class Ui allowed");
    }
    screenInitialized = true;
    ts::Ui::Ncurses::Ncurses::initscr();
    app.init();

    while(state != State::QUIT) {
        switch(state) {
            case State::MAIN_MENU:
                mainMenu();
                break;
            case State::INTRO:
                intro();
                break;
            case State::LOCAL_GAME:
                game = std::make_unique<ts::Ui::Ncurses::LocalGame>();
                game->exec();
                break;
            case State::QUIT:
                break;
            default:
                break;
        }
    }

    ts::Ui::Ncurses::Ncurses::endwin();
    screenInitialized = false;

    return 0;
}

void Ui::intro() {
    ts::Ui::Ncurses::Ncurses::clear();
    ts::Ui::Ncurses::Ncurses::noecho();
    showTitle("BATTLESHIPS", "Press any key to continue");
    ts::Ui::Ncurses::Ncurses::refresh();
    ts::Ui::Ncurses::Ncurses::getch();
    state = State::MAIN_MENU;
}

void Ui::showTitle(const std::string& title, const std::string& subtitle) {
    ts::Ui::Ncurses::Ncurses::curs_set(false);
    std::size_t t(title.size());
    drawBigText(2, (Ncurses::COLS - (t * CHAR_WIDHT + (t - 1) * HORIZONTAL_SPACE)) / 2, title);
    std::size_t st(subtitle.size());
    ts::Ui::Ncurses::Ncurses::mvprintw(10, (Ncurses::COLS - st) / 2, subtitle);
}

void Ui::mainMenu() {
    ts::Ui::Ncurses::Ncurses::clear();
    ts::Ui::Ncurses::Ncurses::noecho();
    showMainMenu();
    ts::Ui::Ncurses::Ncurses::refresh();

    switch (ts::Ui::Ncurses::Ncurses::getch()) {
        case '1':
            break;
        case '2':
            break;
        case 'Q':
        case 'q':
            state = State::QUIT;
            break;
        default:
            break;
    }
}

void Ui::showMainMenu() {
    drawBigText(2, 10, "BATTLESHIPS");
    ts::Ui::Ncurses::Ncurses::mvprintw(10, 15, "1 - Local game");
    ts::Ui::Ncurses::Ncurses::mvprintw(11, 15, "(2 - Network game) IN PROGRESS");
    ts::Ui::Ncurses::Ncurses::mvprintw(12, 15, "Q - Quit");
}

void Ui::drawBigText(std::size_t y, std::size_t x, std::string text) {
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

void Ui::drawBigCharacter(std::size_t y, std::size_t x, char c) {
    switch(c) {
        case 'A':
            for (std::size_t i = x; i <= x + 2; i += 2) {
                for (std::size_t j = y + 1; j <= y + 4; ++j) {
                    ts::Ui::Ncurses::Ncurses::mvprintw(j, i, SYMBOL);
                }
            }
            ts::Ui::Ncurses::Ncurses::mvprintw(y, x + 1, SYMBOL);
            ts::Ui::Ncurses::Ncurses::mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'B':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = y; i <= y + 4; i += 2) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x + 1, SYMBOL);
            }
            for (std::size_t i = y + 1; i <= y + 3; i += 2) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x + 2, SYMBOL);
            }
            break;
        case 'E':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = x + 1; i <= x + 2; ++i) {
                for (std::size_t j = y; j <= y + 4; j += 2) {
                    ts::Ui::Ncurses::Ncurses::mvprintw(j, i, SYMBOL);
                }
            }
            break;
        case 'H':
            for (std::size_t i = x; i <= x + 2; i += 2) {
                for (std::size_t j = y; j <= y + 4; ++j) {
                    ts::Ui::Ncurses::Ncurses::mvprintw(j, i, SYMBOL);
                }
            }
            ts::Ui::Ncurses::Ncurses::mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'I':
            for (std::size_t j = y; j <= y + 4; ++j) {
                ts::Ui::Ncurses::Ncurses::mvprintw(j, x + 1, SYMBOL);
            }
            break;
        case 'L':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 2; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(y + 4, i, SYMBOL);
            }
            break;
        case 'P':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x, SYMBOL);
            }
            ts::Ui::Ncurses::Ncurses::mvprintw(y, x + 1, SYMBOL);
            ts::Ui::Ncurses::Ncurses::mvprintw(y + 1, x + 2, SYMBOL);
            ts::Ui::Ncurses::Ncurses::mvprintw(y + 2, x + 1, SYMBOL);
            break;
        case 'S':
            for (std::size_t i = x + 1; i <= x + 2; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(y, i, SYMBOL);
            }
            for (std::size_t i = 0; i <= 2; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(y + 1 + i, x + i, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 1; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(y + 4, i, SYMBOL);
            }
            break;
        case 'T':
            for (std::size_t i = y; i <= y + 4; ++i) {
                ts::Ui::Ncurses::Ncurses::mvprintw(i, x + 1, SYMBOL);
            }
            for (std::size_t i = x; i <= x + 2; i += 2) {
                ts::Ui::Ncurses::Ncurses::mvprintw(y, i, SYMBOL);
            }
            break;
        default:
            break;
    }
}

} // namespace Ncurses
} // namespace Ui
} // namespace ts
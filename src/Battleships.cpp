#include "Battleships.h"
#include "Field.h"
#include "Ncurses.h"
#include "SettingField.h"
#include "utils.h"
#include <stdexcept>

namespace ts {

bool Battleships::initialized = false;

Battleships::Battleships() : quit(false), state(State::MainMenu) {
    if (initialized) {
        throw std::logic_error("Only one instance of class Battleships allowed");
    }
    initialized = true;
    ts::Ncurses::initscr();

    drawTitle();
    run();
}

Battleships::~Battleships() {
    initialized = false;
    ts::Ncurses::endwin();
}

void Battleships::drawTitle() {
    ts::Ncurses::curs_set(false);
    drawBigText(2, 10, "BATTLESHIPS");
    ts::Ncurses::mvprintw(10, 15, "Press any key");
    ts::Ncurses::getch();
}

void Battleships::run() {
	while(!quit) {
		switch(state) {
		case State::MainMenu:
			showMainMenu();
			break;
		}
	}
}

void Battleships::showMainMenu() {
	ts::Ncurses::clear();
    drawBigText(2, 10, "BATTLESHIPS");
	ts::Ncurses::mvprintw(10, 15, "1 - Local game");
	ts::Ncurses::mvprintw(11, 15, "(2 - Network game) IN PROGRESS");
	ts::Ncurses::mvprintw(12, 15, "Q - Quit");

    ts::Ncurses::noecho();

    switch (ts::Ncurses::getch()) {
    case '1':
    	startLocalGame();
    	break;
    case '2':
    	break;
    case 'Q':
    case 'q':
    	quit = true;
    	break;
    default:
    	quit = true;
    }
}

void Battleships::startLocalGame() {
	if(!setShips()) { return; }
}

bool Battleships::setShips() {
	ts::Ncurses::clear();
	SettingField sField(3, 3);
	drawField(3, 3);
    drawShiplist(10, 3);
	return true;
}

void Battleships::drawField(std::size_t y, std::size_t x) {
	for (char i = 0; i < 9; ++i) {
		ts::Ncurses::mvprintw(y, x + 2 + 2*i, '1' + i);
		ts::Ncurses::mvprintw(y + 2 + 2*i, x, 'a' + i);
		for (char j = 0; j < 9; ++j) {
			ts::Ncurses::mvprintw(y + 2 + 2*i, x + 2 + 2*j, 'O');
		}
	}
	ts::Ncurses::getch();
}

void Battleships::drawShiplist(std::size_t y, std::size_t x) {
	for (char i = 0; i < 9; ++i) {
		ts::Ncurses::mvprintw(y, x + 2 + 2*i, '1' + i);
		ts::Ncurses::mvprintw(y + 2 + 2*i, x, 'a' + i);
		for (char j = 0; j < 9; ++j) {
			ts::Ncurses::mvprintw(y + 2 + 2*i, x + 2 + 2*j, 'O');
		}
	}
	ts::Ncurses::getch();
}

} // namespace ts

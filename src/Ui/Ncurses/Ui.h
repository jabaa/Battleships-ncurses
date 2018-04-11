#ifndef BATTLESHIPS_UI_NCURSESUI_H
#define BATTLESHIPS_UI_NCURSESUI_H

#include "Ui/Ui.h"
#include "Ui/Ncurses/Game.h"
#include <string>
#include <memory>

namespace ts {
namespace Ui {
namespace Ncurses {

class Ui : public ts::Ui::Ui {
public:
    Ui();
    ~Ui() = default;

    int exec() override;
private:
    void intro();
    void showTitle(const std::string& title, const std::string& subtitle);
    void mainMenu();
    void showMainMenu();
    void drawBigText(std::size_t y, std::size_t x, std::string text);
    void drawBigCharacter(std::size_t y, std::size_t x, char c);

    enum class State{MAIN_MENU, INTRO, QUIT, LOCAL_GAME};
    State state;
    static bool screenInitialized;
    std::unique_ptr<Game> game;
};

} // namespace Ncurses
} // namespace Ui
} // namespace ts

#endif //BATTLESHIPS_UI_NCURSESUI_H

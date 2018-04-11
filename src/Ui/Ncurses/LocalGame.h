#ifndef BATTLESHIPS_LOCALGAME_H
#define BATTLESHIPS_LOCALGAME_H

#include "Ui/Ncurses/Game.h"

namespace ts {
namespace Ui {
namespace Ncurses {

class LocalGame : public ts::Ui::Ncurses::Game {
public:
    void exec() override;
private:
    enum class State {QUIT, SET, GAME};

};

} // namespace Ncurses
} // namespace Ui
} // namespace ts

#endif //BATTLESHIPS_LOCALGAME_H

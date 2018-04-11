#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H

#include <string>

namespace ts {
namespace Ui {
namespace Ncurses {

class Game {
public:
    virtual ~Game() = default;
    virtual void exec() = 0;
private:
    void drawField(std::size_t y, std::size_t x);
    void drawShiplist(std::size_t y, std::size_t x);
};

} // namespace Ncurses
} // namespace Ui
} // namespace ts


#endif //BATTLESHIPS_GAME_H

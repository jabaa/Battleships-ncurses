#ifndef BATTLESHIPS_BATTLESHIPS_H
#define BATTLESHIPS_BATTLESHIPS_H

#include <cstddef>

namespace ts {

class Battleships {
public:
    Battleships();
    virtual ~Battleships();

    Battleships(const Battleships& bs) = delete;
    Battleships& operator=(const Battleships& bs) = delete;

private:
    static bool initialized;
    void drawTitle();
    void run();
    bool quit;

    enum class State{MainMenu};
    State state;

    void showMainMenu();
    void startLocalGame();
    bool setShips();
    void drawField(std::size_t y, std::size_t x);
    void drawShiplist(std::size_t y, std::size_t x);
};

} // namespace ts

#endif // BATTLESHIPS_BATTLESHIPS_H

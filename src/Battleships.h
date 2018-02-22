#ifndef BATTLESHIPS_H
#define BATTLESHIPS_H

namespace ts {

class Battleships {
public:
    Battleships();
    ~Battleships();

    Battleships(const Battleships* bs) = delete;
    Battleships& operator=(const Battleships* bs) = delete;

private:
    static bool initialized;
    void drawTitle();
};

}

#endif

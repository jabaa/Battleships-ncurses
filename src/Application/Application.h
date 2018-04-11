#ifndef BATTLESHIPS_BATTLESHIPS_H
#define BATTLESHIPS_BATTLESHIPS_H

#include <cstddef>

namespace ts {

class Application {
public:
    Application() = default;
    virtual ~Application() = default;

    void init();
};

} // namespace ts

#endif // BATTLESHIPS_BATTLESHIPS_H

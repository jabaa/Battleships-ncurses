#ifndef BATTLESHIPS_UI_UI_H
#define BATTLESHIPS_UI_UI_H

#include "Application/Application.h"

namespace ts {
namespace Ui {

class Ui {
public:
    Ui() = default;
    virtual ~Ui() = default;

    virtual int exec() = 0;
protected:
    Application app;
};

}
}

#endif //BATTLESHIPS_UI_UI_H

#ifndef BATTLESHIPS_SETTINGFIELD_H
#define BATTLESHIPS_SETTINGFIELD_H

#include "Field.h"

namespace ts {

class SettingField : public Field {
public:
    SettingField(std::size_t y, std::size_t x);
};

} // namespace ts

#endif // BATTLESHIPS_SETTINGFIELD_H

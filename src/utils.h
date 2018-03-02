#ifndef BATTLESHIPS_UTILS_H_
#define BATTLESHIPS_UTILS_H_

#include <string>
#include <curses.h>

namespace ts {

void drawBigText(std::size_t y, std::size_t x, std::string text);
void drawBigCharacter(std::size_t y, std::size_t x, char c);

} // namespace ts

#endif // BATTLESHIPS_UTILS_H_

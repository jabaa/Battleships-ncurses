#include <string>
#include <ncurses.h>

namespace ts {

void drawText(std::size_t x, std::size_t y, std::string text);
void drawCharacter(std::size_t x, std::size_t y, char c);

}

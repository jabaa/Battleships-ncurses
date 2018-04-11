#include "Ui/Ncurses/Ui.h"
#include <string>

int main(int argc, char** argv) {
    bool noGui(false);
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--noGUI") {
            noGui = true;
        }
    }

    int ret(0);
    if (noGui) {
        ts::Ui::Ncurses::Ui ui;
        ret = ui.exec();
    } else {}

    return ret;
}

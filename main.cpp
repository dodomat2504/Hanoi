#include <iostream>
#include "hanoi.h"


const std::string MENU = "Mit wie vielen Scheiben möchtest du spielen (0=Beenden)? ";

int main() {
    bool running = true;
    while (running) {
        system("cls");
        std::cout << MENU;
        int eingabe;
        std::cin >> eingabe;

        switch (eingabe) {
        case 0: running = false; break;
        default:{
            Hanoi h(eingabe);
            h.startGame();
            break;
        }
        }
    }
    std::cout << "Hoffe es hat Spaß gemacht :D" << std::endl;

    return 0;
}

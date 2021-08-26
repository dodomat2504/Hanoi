#include "hanoi.h"


const std::string MENU = "(12) Von 1 nach 2\n(13) Von 1 nach 3\n(21) Von 2 nach 1\n(23) Von 2 nach 3\n(31) Von 3 nach 1\n(32) Von 3 nach 2\n(9) Reset\n(0) Beenden";

Hanoi::Hanoi(const int scheiben): anzahlScheiben(scheiben) {
    for (int i = anzahlScheiben; i > 0; i--) {
        tuerme[0].push(i);
    }
}

void Hanoi::reset() {
    for (int i = 0; i < anzahlTuerme; i++) {
        while (!tuerme[i].empty()) {
            tuerme[i].pop();
        }
    }
    for (int i = anzahlScheiben; i > 0; i--) {
        tuerme[0].push(i);
    }
}

bool Hanoi::isSwitchPossible(const int t1, const int t2) const {
    if (!tuerme[t2].empty() && !tuerme[t1].empty()) {
        return tuerme[t2].top() > tuerme[t1].top();
    } else if (tuerme[t2].empty() && tuerme[t1].empty()) {
        return false;
    } else if (tuerme[t2].empty()) {
        return true;
    } else {
        return false;
    }
}

void Hanoi::switchScheiben(const int fromTurm, const int toTurm) {
    if (isSwitchPossible(fromTurm, toTurm)) {
        tuerme[toTurm].push(tuerme[fromTurm].top());
        tuerme[fromTurm].pop();
    }
}

void Hanoi::printTuerme() {
    Turm tuerme_Zwischenspeicher[anzahlTuerme];

    if (tuerme[0].empty() && tuerme[1].empty()) std::cout << "Du hast gewonnen du Cuck! :D :D :clap:" << std::endl << std::endl;

    std::cout << "-{1}--{2}--{3}-" << std::endl << std::endl;

    for (int s = anzahlScheiben; s > 0; s--) {
        std::string zeile = "";
        for (int t = 0; t < anzahlTuerme; t++) {
            if (s - tuerme[t].size() == 0) { // Turm t
                const int data = tuerme[t].top();
                tuerme[t].pop();
                tuerme_Zwischenspeicher[t].push(data);
                zeile += "  " + std::to_string(data) + "  ";
            } else {
                zeile += "     ";
            }
        }
        std::cout << zeile << std::endl;
    }
    std::cout << "---------------" << std::endl;

    for (int i = 0; i < anzahlTuerme; i++) {
        while (!tuerme_Zwischenspeicher[i].empty()) {
            tuerme[i].push(tuerme_Zwischenspeicher[i].top());
            tuerme_Zwischenspeicher[i].pop();
        }
    }
}

void Hanoi::startGame() {
    bool running = true;
    int stepCounter = 0;
    while (running) { // Gameloop
        system("cls");
        std::cout << "Steps: " << stepCounter << std::endl;
        printTuerme();
        std::cout << MENU << std::endl << ": ";
        int eingabe;
        std::cin >> eingabe;

        switch (eingabe) {
        case 12: if (isSwitchPossible(0, 1)) {switchScheiben(0, 1); stepCounter++;}; break;
        case 13: if (isSwitchPossible(0, 2)) {switchScheiben(0, 2); stepCounter++;}; break;
        case 21: if (isSwitchPossible(1, 0)) {switchScheiben(1, 0); stepCounter++;}; break;
        case 23: if (isSwitchPossible(1, 2)) {switchScheiben(1, 2); stepCounter++;}; break;
        case 31: if (isSwitchPossible(2, 0)) {switchScheiben(2, 0); stepCounter++;}; break;
        case 32: if (isSwitchPossible(2, 1)) {switchScheiben(2, 1); stepCounter++;}; break;
        case 9: reset(); stepCounter = 0; break;
        case 0: running = false; break;
        default: break;
        }
    }
}

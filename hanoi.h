#ifndef HANOI_H
#define HANOI_H

#include "turm.h"
#include <iostream>


constexpr static const int anzahlTuerme = 3;

class Hanoi {
private:
    Turm tuerme[anzahlTuerme];
    const int anzahlScheiben;

    void reset();
    bool isSwitchPossible(const int t1, const int t2) const;
    void switchScheiben(const int fromTurm, const int toTurm);
    void printTuerme();
public:
    Hanoi(const int scheiben);

    void startGame();

};

#endif // HANOI_H

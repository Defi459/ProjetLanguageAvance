#ifndef ARCHER_H
#define ARCHER_H

#include <iostream>
#include <string>
#include "personnage.h"


class Archer : public Personnage {
    private:
        int energie;
    public:
        Archer(int x, int y);
        void flecheDeFeu(Personnage &cible);
        void flecheDeGlace(Personnage &cible);
        void rechargerEnergie();

        /*** getter setter ***/
        void set_energie(int new_energie);
        int get_energie();
};

#endif // ARCHER_H

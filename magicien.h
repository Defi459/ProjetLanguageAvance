#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN

#include <iostream>
#include <string>
#include "personnage.h"

class Magicien : public Personnage {
    private:
        int mana;

    public:
        Magicien(int x, int y);
        void bouleDeFeu(Personnage &cible);
        void bouleDeGlace(Personnage &cible);
        void rechargerMana();
        void dash(int new_x, int new_y);

        /*** getter setter ***/
        void set_mana(int new_mana);
        int get_mana();

};

#endif

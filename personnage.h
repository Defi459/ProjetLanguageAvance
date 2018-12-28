#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <QString>
#include <iostream>
#include <string>

class Personnage {
    protected:
        int vie;
//        std::string pseudo;
        QString pseudo;
        int point_mouvement;
        int x;
        int y;

    public:
        Personnage();
        Personnage(int new_point_mouvement, int new_x, int new_y);
        void recevoirDegats(int degats);
        void coupDePoing(Personnage &cible) const;
        void perdre_PM(int new_perte);

        /*** getter setter ***/
        void set_vie(int new_vie);
        void set_pseudo(QString new_pseudo);
        void set_point_mouvement(int new_PM);
        void set_x(int new_x);
        void set_y(int new_y);
        int get_vie();
        QString get_pseudo();
        int get_PM();
        int get_x();
        int get_y();
};

#endif

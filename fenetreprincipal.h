#ifndef FENETREPRINCIPAL_H
#define FENETREPRINCIPAL_H

#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QAbstractScrollArea>

#include "fenetrejeu.h"
#include "personnage.h"
#include "map.h"

class FenetrePrincipal : public QWidget {
    Q_OBJECT

    public:
        FenetrePrincipal();

    private slots:
        void ouvrirFenetreJeu();
//        void ouvrirFenetreJeu(Personnage p1, Personnage p2);

    private:
        QLineEdit *champ_player1;
        QLineEdit *champ_player2;
        QLineEdit *champ_map;
        QPushButton *bouton_quit;
        QPushButton *bouton_lancer_jeu;
        QComboBox *select_mode;

};

#endif // FENETREPRINCIPAL_H

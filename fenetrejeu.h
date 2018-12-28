#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <QtWidgets>
#include <QProgressBar>
#include <QGraphicsItem>

#include "personnage.h"
#include "map.h"

class FenetreJeu : public QWidget {
    Q_OBJECT
    public:
//        FenetreJeu(QString pseudo1, QString pseudo2, int mode_jeu);
        FenetreJeu(Personnage p1, Personnage p2, int mode_jeu, Map map);
        void interfaceJeu(Map map);
        void placementWidget();
        void quadrillage(QGraphicsScene *scene);
        void generate_map(QGraphicsScene *scene, Map map);


    private:
        QLabel *nom1;
        QLabel *nom2;
        QLabel *mode;
        QProgressBar *hp_player1;
        QProgressBar *hp_player2;
        QGraphicsScene *scene;
        QGraphicsView *vue;
};

#endif // FENETREJEU_H


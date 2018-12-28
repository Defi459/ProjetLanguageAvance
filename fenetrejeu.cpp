#include "fenetrejeu.h"
#include "personnage.h"

//FenetreJeu::FenetreJeu(QString pseudo1, QString pseudo2, int mode_jeu) : QWidget() {
//    setFixedSize(600, 600);
//    nom1= new QLabel(pseudo1.simplified(), this);
//    nom2= new QLabel(pseudo2.simplified(), this);
////    mode= new QLabel(pseudo2.simplified(), this);

//    hp_player1 = new QProgressBar(this);
//    hp_player1->move(20,20);
//    hp_player1->setMaximum(100);
//    hp_player1->resize(200, 20);
//    hp_player1->setValue(100);

//    hp_player2 = new QProgressBar(this);
//    hp_player2->move(20,20);
//    hp_player2->setMaximum(100);
//    hp_player2->resize(200, 20);
//    hp_player2->setValue(100);

//    placementWidget();

//    interfaceJeu();
//}

FenetreJeu::FenetreJeu(Personnage p1, Personnage p2, int mode_jeu, Map map) : QWidget() {
    setFixedSize(600, 600);
    nom1= new QLabel(p1.get_pseudo().simplified(), this);
    nom2= new QLabel(p2.get_pseudo().simplified(), this);

    if(mode_jeu==0){
        mode= new QLabel("Joueur contre joueur", this);
    }else if(mode_jeu==1){
        mode= new QLabel("Joueur contre Ordinateur", this);
    }else{
        mode= new QLabel("Ordinateur contre Ordinateur", this);
    }


    hp_player1 = new QProgressBar(this);
    hp_player1->move(20,20);
    hp_player1->setMaximum(100);
    hp_player1->resize(200, 20);
    hp_player1->setValue(100);

    hp_player2 = new QProgressBar(this);
    hp_player2->move(20,20);
    hp_player2->setMaximum(100);
    hp_player2->resize(200, 20);
    hp_player2->setValue(100);

    placementWidget();

    interfaceJeu(map);
}

void FenetreJeu::quadrillage(QGraphicsScene *scene){
    for(int s=0; s<16; s++){
        QLine ligne(0, s*50, 750, s*50);
        scene->addLine(ligne);
    }
    for(int s=0; s<16; s++){
        QLine ligne(s*50, 0, s*50, 750);
        scene->addLine(ligne);
    }

}

void FenetreJeu::generate_map(QGraphicsScene *scene, Map map){

    for(int i=0; i<15; i++){
        for (int j=0; j<15; j++){
            if(map.getmap(i,j)!=0){
                if(map.getmap(i,j)==1){
                    //On met joueur1
                }
                if(map.getmap(i,j)==2){
                    //On met joueur2
                }
                if(map.getmap(i,j)==3){
                    QPen pen(Qt::black,1,Qt::SolidLine);
                    QBrush brush(Qt::green,Qt::Dense2Pattern);
                    scene->addRect(i*50, j*50, 50, 50, pen, brush);
                }
                if(map.getmap(i,j)==4){
                    QPen pen(Qt::black,1,Qt::SolidLine);
                    QBrush brush(Qt::gray,Qt::SolidPattern);
                    scene->addRect(i*50, j*50, 50, 50, pen, brush);
                }
                if(map.getmap(i,j)==5){
                    QPen pen(Qt::black,1,Qt::SolidLine);
                    QBrush brush(Qt::green,Qt::Dense2Pattern);
                    scene->addRect(i*50, j*50, 50, 50, pen, brush);
                }
                if(map.getmap(i,j)==6){
                    QPen pen(Qt::black,1,Qt::SolidLine);
                    QBrush brush(Qt::gray,Qt::SolidPattern);
                    scene->addRect(i*50, j*50, 50, 50, pen, brush);
                }
            }
        }
    }
}

void FenetreJeu::interfaceJeu(Map map){
    //scene = new QGraphicsScene(150, -150, 1000, 1000, this);
    scene = new QGraphicsScene();
    quadrillage(scene);
    generate_map(scene,map);


    //    scene->addText("Hello world !");
    vue = new QGraphicsView(scene);
    vue->setFixedSize(850,850);
    vue->show();

//Rectangle
    QRect rectangle(2, 2, 45, 45);
    QPen pen_bleu(Qt::blue, 1, Qt::SolidLine);
    QBrush bleu(Qt::blue);
//    scene->addRect(rectangle, pen_bleu, bleu);

//Triangle
    QPolygon polygon;
    polygon << QPoint(25, 2) << QPoint(2, 48) << QPoint(48, 48);
    QPen pen_green(Qt::blue, 1, Qt::SolidLine);
    QBrush vert(Qt::green);
//    scene->addPolygon(polygon, pen_green, vert);

//Cercle
//    QRect rectangle(10, 10, 100, 50);
    QPen pen_red(Qt::red, 1, Qt::SolidLine);
    QBrush red(Qt::red);
//    scene->addEllipse(rectangle, pen_red, red);

//Losange
    QPolygon losange;
    losange << QPoint(2, 25) << QPoint(25, 2) << QPoint(48, 25) << QPoint(25, 48);
    scene->addPolygon(losange, pen_red, red);



//    scene->setBackgroundBrush(Qt::blue);
//    scene->setBackgroundBrush(QColor(0, 0, 0, 255));
    scene->setBackgroundBrush(QColor("#c0c0c0"));
}

void FenetreJeu::placementWidget(){

    QHBoxLayout *layout_modeJeu = new QHBoxLayout;
    layout_modeJeu->addWidget(mode);

    QHBoxLayout *nom_des_joueurs = new QHBoxLayout;
    nom_des_joueurs->addWidget(nom1);
    nom_des_joueurs->addWidget(nom2);

    QHBoxLayout *barre_de_vie = new QHBoxLayout;
    barre_de_vie->addWidget(hp_player1);
    barre_de_vie->addWidget(hp_player2);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(layout_modeJeu);
    layout->addRow(nom_des_joueurs);
    layout->addRow(barre_de_vie);

    this->setLayout(layout_modeJeu);
    this->setLayout(nom_des_joueurs);
    this->setLayout(barre_de_vie);
    this->setLayout(layout);

//        QGridLayout *layout = new QGridLayout;
//            layout->addWidget(nom1, 0, 0);
//            layout->addWidget(nom2, 0, 1);
//            layout->addWidget(hp_player1, 1, 0);
//            layout->addWidget(hp_player2, 1, 1);

//        this->setLayout(layout);
}

#include "fenetreprincipal.h"

FenetrePrincipal::FenetrePrincipal() : QWidget() {
    setFixedSize(600, 300);

    champ_player1= new QLineEdit("Player 1", this);
    champ_player1->setMaxLength(15);
    champ_player1->setProperty("mandatoryField", true); //Mettre obligatoire le champ
    champ_player1->selectAll();

    champ_player2= new QLineEdit("Player 2", this);
    champ_player2->setMaxLength(15);
    champ_player2->setProperty("mandatoryField", true);

    champ_map= new QLineEdit("/home/user/Bureau/projetlanguageavancé/map/",this);

    select_mode=new QComboBox(this);
    select_mode->addItem("Joueur contre Joueur");
    select_mode->addItem("Joueur contre Ordinateur");
    select_mode->addItem("Ordinateur contre Ordinateur");

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Pseudo du joueur 1:", champ_player1);
    layout->addRow("Pseudo du joueur 2:", champ_player2);
    layout->addRow("Selectionner la map", champ_map);
    layout->addRow("Selection du mode de jeu:", select_mode);

    this->setLayout(layout);

//Bouton pour passer a la suite
    bouton_lancer_jeu = new QPushButton("Lancer le jeu!", this);
    bouton_lancer_jeu->setFont(QFont("FreeMono", 9));
    bouton_lancer_jeu->setCursor(Qt::PointingHandCursor);
    bouton_lancer_jeu->move(60, 250);
    bouton_lancer_jeu->setToolTip("Amusez vous bien!");

    QObject::connect(bouton_lancer_jeu, SIGNAL(clicked()), this, SLOT(ouvrirFenetreJeu()));
//    QObject::connect(bouton_lancer_jeu, SIGNAL(clicked()), this, SLOT(ouvrirFenetreJeu(Personnage, Personnage)));

//Bouton quitter
    bouton_quit = new QPushButton("Quitter", this);
    bouton_quit->setFont(QFont("FreeMono", 12));
    bouton_quit->setCursor(Qt::PointingHandCursor);
    bouton_quit->move(200, 250);
    bouton_quit->setToolTip("Vous nous quittez déjà? :(");

    QObject::connect(bouton_quit,SIGNAL(clicked()), qApp, SLOT(quit()));
}

void FenetrePrincipal::ouvrirFenetreJeu(){

    Personnage p1(3, 0, 0);
    Personnage p2(3, 10, 10);
    Map map;

    if (champ_player1->text().isEmpty()) {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer un nom pour le joueur 1.");
            return; // Arrêt de la méthode
    }

    if (champ_player2->text().isEmpty()) {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer un nom pour le joueur 2.");
            return;
    }

    if (champ_map->text().isEmpty()) {
        QMessageBox::critical(this,"Attention !","Pas de map entrée. Génération aléatoire.");
        map.random_map();
    }
    else{
       std::string fichier=champ_map->text().toStdString().c_str();
       map.ouvrir_map(fichier);
    }

    p1.set_pseudo(champ_player1->text());
    p2.set_pseudo(champ_player2->text());
    //map.ouvrir_map("/home/user/Bureau/projetlanguageavancé/map/map1.txt");

    FenetreJeu *fenetreJ = new FenetreJeu(p1, p2, select_mode->currentIndex(), map);
    fenetreJ->show();
}

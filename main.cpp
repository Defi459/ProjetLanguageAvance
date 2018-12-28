#include <QApplication>
#include "fenetreprincipal.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    Personnage p1(3, 0, 0);
//    Personnage p2(3, 10, 10);

    FenetrePrincipal fenetreP;
    fenetreP.show();


    return app.exec();
}

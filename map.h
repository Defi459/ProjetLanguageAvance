#ifndef MAP_H
#define MAP_H

#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QTextStream>


using namespace std;


class Map {
    protected:
        int map[15][15];

    public:
        Map();
        void ouvrir_map(string mon_fichier);
        void random_map();


        int getmap(int x,int y);

};

#endif // MAP_H

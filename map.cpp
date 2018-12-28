#include "map.h"


using namespace std;


Map::Map() { for(int i=0; i < 15; i++){for(int j=0; j < 15; j++){ map[i][j]=0; }} }

void Map::random_map(){
    srand(time(NULL));
    int r=0;
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            if(map[i][j]==0){
                r=rand()%30;
                if(r==3){
                    this->map[i][j]=3;
                    if(j+1<15){
                        this->map[i][j+1]=5;
                    }
                    if(j+2<15){
                        this->map[i][j+2]=5;
                    }
                }
                if(r==4){
                    this->map[i][j]=4;
                    if(j+1<15){
                        this->map[i][j+1]=6;
                    }
                    if((j+1 < 15) && (i+1 < 15)){
                        this->map[i+1][j+1]=6;
                    }
                    if(i+1<15){
                        this->map[i+1][j]=6;
                    }
                }
            }
        }
    }
}

void Map::ouvrir_map(string mon_fichier){
    ifstream fichier(mon_fichier);
    char id;
    if(fichier){
        for(int j=0; j<15;j++){
            int i=0;
            fichier.get(id);
            while(id!='\n'){
                if(id=='1'){
                    this->map[i][j]=1;
                }
                if(id=='2'){
                    this->map[i][j]=2;
                }
                if(id=='3'){
                    this->map[i][j]=3;
                }
                if(id=='4'){
                    this->map[i][j]=4;
                }
                if(id=='5'){
                    this->map[i][j]=5;
                }
                if(id=='6'){
                    this->map[i][j]=6;
                }
                fichier.get(id);
                i=i+1;
            }
        }
    }
    else{
        cerr << "Impossible d'ouvrir le fichier." << endl;
    }

}


int Map::getmap(int x, int y){return this->map[x][y];}

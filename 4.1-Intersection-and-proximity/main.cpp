#include <iostream>
#include <vector>
using namespace std;

//O(1)
int direccion(int x1,int y1,int x2,int y2,int x3,int y3){
    int funcion=((y2-y1)*(x3-x2))-((y3-y2)*(x2-x1));

    if (funcion<0){

        return -1;
    }

    else if(funcion>0){

        return 1;
    }

    return 0;
}

//O(1)
bool interseccion(int p1x, int p1y,int q1x, int q1y,int p2x, int p2y,int q2x, int q2y){
    if(direccion(p1x,p1y,q1x,q1y,p2x,p2y)!=direccion(p1x,p1y,q1x,q1y,q2x,q2y)){

        if(direccion(p2x,p2y,q2x,q2y,p1x,p1y)!=direccion(p2x,p2y,q2x,q2y,q1x,q1y)){

            return 1;

        }

    }
    return 0;
}

//O(n)
void coordenadas(vector<int> puntos){
    if(puntos.empty() == false){
        cout<<interseccion(puntos[0],puntos[1],puntos[2],puntos[3],puntos[4],puntos[5],puntos[6],puntos[7])<<endl;
        puntos.erase(puntos.begin(),puntos.begin()+8);
        coordenadas(puntos);
    }
}

//O(n)
int main(){
    int n;
    int punto;
    vector<int> puntos;

    //O(n)
    do{
        cin>>n;
        if(n%4 !=0 || n==0){
          cout << "Introduzca un numero multiplo del 4" << endl;
        }
    } while(n%4 !=0 || n==0);

    //O(n)
    for (int i=0; i<n*2; i++){
        cin>>punto;
        puntos.push_back(punto);
    }

    //O(n)
    coordenadas(puntos);


    return 0;
}

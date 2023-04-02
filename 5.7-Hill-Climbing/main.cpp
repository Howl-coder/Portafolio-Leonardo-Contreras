#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

//O(1)
bool pendiente(int x1,int y1,int x2, int y2){
    float yS = y2-y1;
    float xS = x2-x1;

    if (xS != 0){
      float var = yS/xS;
      if(var==1 || var ==-1){
          return 1;
      }
    }
    return 0;
}

//O(n^3)
void solucion(vector<vector<int> > &tablero,int n){
    vector<int> x;
    vector<int> y;
    vector<int>::iterator it;
    vector<int> temp;
    int heuristica;
    int temph;
    int tempx;
    int tempy;
    int j;
    srand(time(NULL));

    //O(n^3)
    for(int i=0; i<n;i++){ //y
        heuristica= INT_MAX;
        temp.erase(temp.begin(),temp.end());

        //O(n^2)
        while(heuristica!=0 && temp.size()<n){ //x
            temph =0;
            j= rand()% (n);
            it = find(temp.begin(), temp.end(), j);

            if (it == temp.end()){
                //O(n)
                for(int m=0; m<x.size(); m++){
                    if(y[m]==i || x[m] == j || pendiente(j,i,x[m],y[m])){ //O(1)
                        temph++;
                    }
                }
                if(temph<heuristica){
                    heuristica= temph;
                    tempx=j;
                    tempy=i;
                }
                temp.push_back(j);
            }
        }

        x.push_back(tempx);
        y.push_back(tempy);
        tablero[tempx][tempy] =1;
    }

}

//O(n^3)
int main(){
    int n;
    cin>>n;

    vector<vector<int> > tablero( n , vector<int> (n, 0));

    solucion(tablero,n); //O(n^3)

    //O(n^2)
    for(int i=0; i<n;i++){
        for (int j=0; j<n; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

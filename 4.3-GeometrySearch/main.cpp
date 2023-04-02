#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//O(n^2)
void bubbleSort(vector<double> &x,vector<double> &y, int n){
    int i, j;
    int temp;

    int temp2;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (x[j] > x[j + 1]){
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;

                temp2=y[j];
                y[j]=y[j+1];
                y[j+1]=temp2;
            }
        }
    }
}

//O(1)
double dist(double x1,double y1,double x2, double y2 ){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

//O(n)
double solucion(vector<double> &x,vector<double> &y,int inicio,int final){
    if(final==inicio+1){
        return dist(x[inicio],y[inicio],x[final],y[final]);
    }
    else if(inicio==final){
        return INT_MAX;
    }

    int mitad= (inicio+final)/2;
    double mita=solucion(x,y,inicio,mitad);
    double mata=solucion(x,y,mitad+1,final);

    double min;
    double rango;

    if(mita>mata){
        min=mata;
    }
    else{
        min=mita;
    }

    rango=min;
    double m= x[mitad]+x[mitad+1]/2;

    for(int i=inicio;i<mitad+1;i++){ //O(n^2)
       if(x[i]>=m-rango || x[i]<=m+rango){
            for(int j=mitad+1; j<final+1;j++){ //O(n)
                if(x[j]>=m-rango || x[j]<=m+rango){
                    mita=dist(x[i],y[i],x[j],y[j]);
                    if(mita<min){
                        min=mita;
                    }
                }
            }
       }
    }

    return min;
}

//O(n^2)
int main(){
    int n;
    cin>>n;
    vector<double> x;
    vector<double> y;
    double temp;

    for( int i=0; i<n;i++){ //O(n)
        cin>>temp;
        x.push_back(temp);
        cin>>temp;
        y.push_back(temp);
    }

    bubbleSort(x,y,n); //O(n^2)

    cout << solucion(x,y,0,n-1) << endl; //O(n)

    return 0;
}

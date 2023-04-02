#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

void bubbleSort(int pesos[],int valores[], int n)//O(n^2)
{
    int i, j;
    int temp;

    int temp2;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){ 
            if (pesos[j] > pesos[j + 1]){
                temp=pesos[j];
                pesos[j]=pesos[j+1];
                pesos[j+1]=temp;

                temp2=valores[j];
                valores[j]=valores[j+1];
                valores[j+1]=temp2;

                
            }
        }
    }
}



int max(int valores[], int pesos[], int w,int n){ //O(n^3)
    int k;
    int sump;
    int sumv=0;
    int temp;
    
    for(int i=0; i<n;i++){
        k=i+1;
        while(k<n){
            sump=0;
            temp=0;
            if(sump+pesos[i]<=w){
                sump=pesos[i];
                temp=valores[i];
                for(int j=k;j<n;j++){
                    if(sump+pesos[j]<=w){
                        sump=sump+pesos[j];
                        temp=temp+valores[j];
                        
                    }
                }
                if(sumv<temp){
                    sumv=temp;
                }
                k++;
                
            }else{
                k=n;
            }
                  
        }
   
    }
    cout<<endl;
    return sumv;
}

int main(){ //O(n^3)
 int n;
 cin>>n; 
 int valores[n];
 int pesos[n];
 int v;
 int p;
 int w;
 
 for (int i=0; i<n; i++){
    cin>>v;
    valores[i]=v;
 }
 for (int i=0; i<n; i++){
    cin>>p;
    pesos[i]=p;
 }

 
    cin>>w;
    bubbleSort(pesos,valores, n);
    cout<<max(valores,pesos,w,n);

 return 0;



}
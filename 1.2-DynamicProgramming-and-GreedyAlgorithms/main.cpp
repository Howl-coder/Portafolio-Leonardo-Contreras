#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<int> &V)
{
  for(int x: V)
    {
    cout << x << " pesos"<<endl;
    
    }
}

void add(vector<int> &V,int x){
    V.push_back(x);
    
}

void dinamico(vector<int> &N, int P, int Q){
    int cam = Q-P;
    vector <int> temp;
    vector <int> temp2;
    if(Q == P){
        cout<<"el cambio es 0"<< endl;
    }
    if(Q<P){
        cout<<"no alcanza"<<endl;
    }else{
        sort(N.begin(), N.end());
        int lim=cam/N[0];
        for(int i=0; i<lim;i++){
            temp.push_back(N[0]);
        }
        int indexN= N.size()-1;

        while(indexN>0){
            int index=0;
            int sum = 0;
            while(index<temp.size() ){
                if(sum+temp[index]<N[indexN]){
                    sum += temp[index];
                    
                }else if(sum+temp[index]==N[indexN]){
                    sum = 0;
                    temp2.push_back(N[indexN]);
                }else{
                    sum = 0;
                }
                index += 1;
            }
            int suma=0;
            for (int i=0; i<temp2.size(); i++){
                suma += temp2[i];
            }
           
            int indexR = 0;
            while(suma<cam){
                if (suma + temp[indexR] <= cam){
                    temp2.push_back(temp[indexR]);
                }
                suma += temp[indexR];
                indexR += 1;
            }
            temp=temp2;
            temp2.erase(temp2.begin(),temp2.end());
            
            

            indexN -= 1;
        }
        sort(temp.begin(), temp.end(),greater<int>());
        print_vector(temp);
       
    }

}

int cambio(vector<int> &N, int P, int Q){

    vector<int> C;
    if(Q == P){
        cout<<"el cambio es 0"<< endl;
    }
    if(Q<P){
        cout<<"no alcanza"<<endl;
    }
    if(Q >P){
        int cam = Q-P;
        vector<int>::iterator it;
        
        it = find(N.begin(), N.end(),cam);
        if (it != N.end()){
            cout<< "El cambio es " <<cam<<endl;  
        }else{
                sort(N.begin(), N.end(), greater<int>());
                 int sum=0;
                 
                 auto index=0;
                 while(sum<cam && index<N.size()){
                    if(sum+N[index]<=cam){
                        sum+=N[index];
                        C.push_back(N[index]);
                    }else{
                        index+=1;
                    }
                 }
                print_vector(C);
                
        }
            
     }
     return 0;
}

int main(){

    vector<int> N; //Vector de monedas
    int m;// Numero de monedas
    cout<<"monedas"<<endl;
    cin>>m;// Insertar numero de monedas
    int n; // valor de las monedas
    for( int i=0; i < m; i++){
        cout<<"valores"<<endl;
        cin>>n;// insertar valor de las monedas 
        add(N,n); // añadir monedas al vector de monedas
    }
    int precio;
    cout<<"precios"<<endl;
    cin>>precio;
    int Q;
    cout<<"billete"<<endl;
    cin>>Q;
    cambio(N,precio,Q);
    cout<<"dinamico"<<endl;
    dinamico(N,precio,Q);

    

    return 0;
}
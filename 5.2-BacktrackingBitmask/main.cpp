#include <iostream>
#include <vector>

using namespace std;

//O(n*m)
void outfits(vector<int> &gorras, vector<int> &personas, int n){
    int ng=gorras.size();
    int prim = 0 ;
    int pact = 0;
    int index;
    int trues = 0;
    vector<bool> visitado;
    visitado = vector<bool>(ng, false);
    vector<int> temp;
    vector<int> vari;
    vector<int>::iterator tr;

    //O(n*m)
    while(trues<visitado.size()){
        //O(n)
        for(int j = 0; j < ng; j++){
            if(temp.empty() && !visitado[j]){
                temp.push_back(gorras[j]);
                visitado[j]=true;
                pact=1;
            }
            else if(pact==personas[j] && !visitado[j]){
                tr = find (temp.begin(), temp.end(), gorras[j]);

                if (tr == temp.end()){
                    temp.push_back(gorras[j]);
                    visitado[j]=true;
                    pact+=1;
                }
                else{
                    visitado[j]=true;
                }
            }
            else if(personas[j]>pact){
                visitado[j]=true;
            }
        }

        trues = 0;
        //O(n)
        for(int x = 0; x < visitado.size(); x++){
            if(visitado[x]){
                trues+=1;
            }
            else{
                index = x;
            }
        }

        if(temp.size() == n){
            vari.insert(vari.end(), temp.begin(), temp.end());
        }

        if(trues < visitado.size()){
            pact = personas[index];
            fill(visitado.begin() + index, visitado.end() , false);
            temp.erase(temp.begin() + pact, temp.end());
        }
    }

    int cont = 1;
    cout << vari.size()/n << endl;

    //O(n)
    for(int i = 0; i < vari.size(); i++){
      if (cont == 1){
        cout << "(" << vari[i]<<",";
        cont += 1;
      }
      else if(cont == n){
        cout<< " " << vari[i] << ")" << endl;
        cont = 1;
      }
      else{
        cout << " " << vari[i] << ",";
        cont += 1;
      }
    }
}

//O(n*m)
int main(){
    int n;
    string linea;
    string temp="";

    //O(n)
    do {
      cout << "Ingrese un numero del 1 al 10" << endl;
      getline(cin,linea);
      n = stoi(linea);
    } while (n < 1 || n > 10);

    vector<int> gorras;
    vector<int> personas;

    //O(n*m)
    for(int i=0; i<n;i++){
        getline(cin,linea);
        for (int j=0;j<linea.size();j++){
            if(linea[j]!=' '){
                temp+= linea[j];
            }
            else if(temp!=""){
                gorras.push_back(stoi(temp));
                temp= "";
                personas.push_back(i);
            }
        }

        if(temp!=""){
            gorras.push_back(stoi(temp));
            temp= "";
            personas.push_back(i);
        }

        if(i==0){
            int gprim = gorras.size();
        }
    }

    outfits(gorras,personas,n);

    return 0;
}

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//O(n)
int busqueda(vector<int> lista, int inicio, int fin, int dato){
  if (inicio <= fin){
    int par = (fin - inicio) + 1;
    srand (time(NULL));
    int indice = rand() % par + inicio;

    if (lista[indice] != dato && (inicio == fin)){
      return -1;
    }
    else if (lista[indice] == dato){
      return indice;
    }
    else if (dato < lista[indice]){
      return busqueda(lista, inicio, indice-1, dato);
    }
    else if (dato > lista[indice]){
      return busqueda(lista, indice+1, fin, dato);
    }
  }

  return -1;
}

//O(n)
int main(){
  int n;
  string linea;

  getline(cin, linea);
  n = stoi(linea);
  getline(cin, linea);

  vector<int> lista;

  string tmp = "";

  //O(n)
  for (int i = 0; i < linea.size(); i++){
    if (linea[i] != ' ' && linea[i] != ','){
      tmp += linea[i];
    }
    else if (tmp != ""){
      lista.push_back(stoi(tmp));
      tmp = "";
    }
  }

  if (tmp != ""){
    lista.push_back(stoi(tmp));
    tmp = "";
  }

  int indice = busqueda(lista, 0, lista.size()-1, n); //O(n)

  if (indice != -1){
    cout << "El elemento esta presente en el indice: " << indice << endl;
  }
  else{
    cout << "El elemento no esta presente en el arreglo" << endl;
  }

  return 0;
}

#include <iostream>
using namespace std;

//O(n^3)
int main(){
  int n;
  cin >> n;

  int adya[n][n];
  int completo = 0;
  int colores[n];
  int color = 0;
  bool mismo = false;

  //O(n^2)
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> adya[i][j];
      if (adya[i][j] == 0){
      }
    }
  }

  //O(n)
  for (int i = 0; i < n; i++){
    colores[i] = -1;
  }

  //O(n^3)
  while (completo < n) {
    //O(n^2)
    for (int indice = 0; indice < n; indice++){
      mismo = false;
      //O(n)
      for (int adyI = (indice-1); adyI >= 0 && !mismo; adyI--){
        if (adya[indice][adyI] == 1){
          if (colores[adyI] == color){
            mismo = true;
          }
        }
      }

      if (!mismo && colores[indice] == -1){
        colores[indice] = color;
      }
    }
    color++;

    completo = 0;
    //O(n)
    for(int m = 0; m < n; m++){
      if (colores[m] > -1){
        completo++;
      }
    }
  }

  cout << endl;

  //O(n)
  if(color < n){
    for (int j = 0; j < n; j++){
        cout << "Node: " << j <<", Assigned Color: " << colores[j] << endl;
    }
  }
  else{
    cout << "No es posible asignar colores a los nodos" << endl;
  }

  return 0;
}

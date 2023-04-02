#include <iostream>
#include <vector>
using namespace std;

int minimo(vector<bool> &activo, vector<int> &caminos, int n){//O(n)
  int min = INT_MAX;
  int index = 0;

  for (int i = 0; i < n; i++){
    if(activo[i] && caminos[i] < min){
      min = caminos[i];
      index = i;
    }
  }

  return index;
}

int main(){ //O(n^3 +m)
  int n;
  int peso;
  int min;
  int completo = 0;

  cin >> n;

  vector<vector<int> > matriz(n, vector<int> (n));
  vector<vector<int> > floyd(n, vector<int> (n));
  vector<bool> activo(n);
  vector<int> caminos(n);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> peso;
      matriz[i][j] = peso;
    }
  }

  cout << "Dijkstra:" << endl;
  for(int i = 0; i < n; i++){
    fill(activo.begin(), activo.end(), true);
    fill(caminos.begin(), caminos.end(), INT_MAX);
    caminos[i] = 0;
    completo = 0;

    while(completo < n){
      min = minimo(activo, caminos, n);
      activo[min] = false;

      for(int j = 0; j < n; j++){
        if ((matriz[min][j] + caminos[min]) < caminos[j] && matriz[min][j] >= 0){
          caminos[j] = matriz[min][j] + caminos[min];
        }
      }

      completo = 0;
      for(int m = 0; m < n; m++){
        if (!activo[m]){
          completo++;
        }
      }
    }

    for(int j = 0; j < n; j++){
      floyd[i][j] = caminos[j];
      if (caminos[j] != 0){
        cout << "node " << i+1 << " to node " << j+1 << ": " << caminos[j] << endl;
      }
    }
}

  cout << endl;
  cout << "Floyd:" << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << floyd[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

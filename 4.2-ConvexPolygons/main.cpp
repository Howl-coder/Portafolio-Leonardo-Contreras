#include <iostream>
#include <vector>

using namespace std;

//O(1)
int direccion(int x1,int y1,int x2,int y2,int x3,int y3){
    int funcion=((y2-y1)*(x3-x2))-((y3-y2)*(x2-x1));

    if (funcion < 0){
        return -1;
    }
    else if(funcion > 0){
        return 1;
    }
    return 0;
}

//O(n^2)
void ordenamiento(vector<int> &figura, int x[],int y[], int n){
  int temp;
  int dir;
  for (int i = 1; i < n - 1; i++){
    for (int j = i+1; j < n; j++){
      dir = direccion(x[figura[0]], y[figura[0]], x[figura[i]], y[figura[i]], x[figura[j]], y[figura[j]]);
      if (dir != -1){
        swap(figura[i], figura[j]);
        j = i;
      }
    }
  }
}

//O(n)
int coorAbajo(int x[], int y[], int n){
  int yMin = INT_MAX;
  int indice;

  for (int i = n-1; i >= 0; i--){
    if (y[i] < yMin){
      yMin = y[i];
      indice = i;
    } else if (y[i] == yMin){
      if (x[i] < x[indice]){
        indice = i;
      }
    }
  }

  return indice;
}

//O(n)
void dibujo(vector<int> &figura, int x[],int y[]){
  int primCoor = 0;
  int curCoor = 1;
  int sigCoor;
  int dir;

  while (curCoor != figura.size()-1){
    sigCoor = curCoor + 1;

    dir = direccion(x[figura[primCoor]], y[figura[primCoor]], x[figura[curCoor]], y[figura[curCoor]], x[figura[sigCoor]], y[figura[sigCoor]]);

    if (dir == -1 || dir == 0){
      primCoor = curCoor;
      curCoor = sigCoor;
    }
    else {
      figura.erase(figura.begin()+curCoor);
      curCoor = primCoor;
      primCoor = primCoor-1;
    }
  }
}

//O(n^2)
int main(){
  int n;
  int primCoor;

  cin >> n;

  int x[n];
  int y[n];
  vector<int> figura;

  //O(n)
  for (int i = 0; i < n; i++){
    cin >> x[i];
    cin >> y[i];
  }

  primCoor = coorAbajo(x, y, n); //O(n)

  //O(n)
  for (int i = 0; i < n; i++){
    if (i != primCoor){
      figura.push_back(i);
    }
  }

  figura.insert(figura.begin(), primCoor);
  ordenamiento(figura, x, y, n); //O(n^2)
  figura.push_back(primCoor);
  dibujo(figura, x, y); //O(n)

  //O(n)
  for (int i = 0; i < figura.size(); i++){
    cout << "(" << x[figura[i]] << "," <<  y[figura[i]] << ")" << endl;
  }

  return 0;
}

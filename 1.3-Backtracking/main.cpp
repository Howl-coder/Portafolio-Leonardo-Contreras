#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void SetFinalMatrix(vector<vector<int>> &matrix, vector<pair<int,int>> posicionesFinales){

  for(pair<int, int>posicion : posicionesFinales)
    matrix[posicion.first][posicion.second] = 1; 

}

//O(n*m)
vector<vector<int>> ramificacionPoda(vector<vector<int>> laberinto){


  
  queue<pair<pair<int, int>, vector<pair<int, int>>>> recorridos;
  vector<pair<int, int>> tmp = {{0,0}};

  recorridos.push(make_pair(make_pair(0,0), tmp));
  pair<pair<int, int>, vector<pair<int, int>>> posActual; 

  int i = 0, j = 0, colSize = laberinto.size(), rowSize = laberinto[0].size();

  while(!recorridos.empty()){ 

    posActual = recorridos.front();
    i = posActual.first.first; j = posActual.first.second;


    if(i == colSize-1 && j == rowSize-1){

      vector<vector<int>> resultado(colSize, vector<int> (rowSize, 0)); 
      SetFinalMatrix(resultado, posActual.second); 
      return resultado;

    }

    
    if(j+1 < rowSize && laberinto[i][j+1]){

      
      tmp = posActual.second;
      tmp.push_back({make_pair(i, j+1)}); 
      recorridos.push(make_pair(make_pair(i, j+1), tmp)); 

    }

   
    if(i+1 < colSize && laberinto[i+1][j]){
      
      tmp = posActual.second;
      tmp.push_back({make_pair(i+1, j)});
      recorridos.push(make_pair(make_pair(i+1, j), tmp));

    }

    
    if(j-1 >= 0 && laberinto[i][j-1]){

      tmp = posActual.second;
      tmp.push_back({make_pair(i, j-1)});
      recorridos.push(make_pair(make_pair(i, j-1), tmp));

    }

    
    if(i-1 >= 0 && laberinto[i-1][j]){
      
      tmp = posActual.second;
      tmp.push_back({make_pair(i-1, j)});
      recorridos.push(make_pair(make_pair(i-1, j), tmp));

    }

    laberinto[i][j] = 0; 
    recorridos.pop(); 

  }

  
  return vector<vector<int>>(colSize, vector<int>(rowSize, 0));

}

bool backtracking(vector<vector<int>> &maze, int x, int y,vector<vector<int>> &temp,int M,int N);

void print(vector<vector<int>> &temp,int M,int N){
    
    for(int a = 0; a < M; a++)
    {
        for(int b = 0; b < N; b++)
        {
            cout << temp[a][b] << " ";
        }
        cout<< endl;
    }
}

bool safe(vector<vector<int>> &maze, int x, int y,int M,int N){
	
	if (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1){
		return true;
    }
	return false;
}



bool back(vector<vector<int>> &maze,int M,int N)
{
    
	vector<vector<int>> temp( M , vector<int> (N));
    for(int a = 0; a < M; a++) 
    {
        for(int b = 0; b < N; b++)
        {
            temp[a][b] = 0;
        }
        
    }
   
	if (backtracking(maze, 0, 0, temp, M,N) == false) {
		cout<<"No hay solucion";
		return false;
	}
	print(temp,M,N);
	return true;
}
//O(n*m)
bool backtracking(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &temp, int M,int N)
{
	
	if (x == M - 1 && y == N - 1 && maze[x][y] == 1) {
		temp[x][y] = 1;
		return true;
	}

	if (safe( maze, x, y, M, N) == true) {
		
		if (temp[x][y] == 1){
			return false;
        }
		
		temp[x][y] = 1;
	
		if (backtracking(maze, x + 1, y, temp,M,N) == true){
			return true;
        }
	
		if (backtracking(maze, x, y + 1, temp,M,N) == true){
			return true;
        }
		
		temp[x][y] = 0;
		return false;
	}
	return false;
}

int main (){

    int M ;
    int N ;
    int i = 0;
    int j = 0;
    cin>>M;
    cin>>N;
    vector<vector<int>> maze( M , vector<int> (N));
   

    for(int a = 0; a < M; a++) 
    {
        for(int b = 0; b < N; b++)
        {
            int v;
            cin>>v;
            maze[a][b] = v;
        }
        
    }

    
    
    
    cout<<endl;
    back(maze,M,N);
    maze=ramificacionPoda(maze);
    cout<<endl;
    for(int i = 0; i < M; i++){

    for (int j = 0; j < N; j++)
      cout << maze[i][j] << " ";

    cout << endl;

  }

    return 0;
    
}
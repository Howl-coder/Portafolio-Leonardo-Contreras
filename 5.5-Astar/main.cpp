#include <iostream>
#include <vector>

using namespace std;

//O(n^2)
void movimientos(vector<vector<int> > &matrix,int x,int y,int n){
    int h= INT_MAX;
    int temp;
    string dir;
    int tempx;
    int tempy;

    if(x!=n-1 || y!=n-1){

        if(x!=n-1){

            if(matrix[x+1][y]==1 ){

                temp= ((n-1)-(x+1)) + ((n-1)-y);
                if(h>temp){
                    h=temp;
                    dir="R";
                    tempx=x+1;
                    tempy=y;

                }

            }

        }
        if(x!=0){
            if(matrix[x-1][y]==1 ){
                temp= ((n-1)-(x-1)) + ((n-1)-y);
                if(h>temp){
                    h=temp;
                    dir="L";
                    tempx=x-1;
                    tempy=y;

                }
            }

        }
        if(y!=n-1){
              if(matrix[x][y+1]==1 ){
                temp= ((n-1)-(x)) + ((n-1)-(y+1));
                if(h>temp){
                    h=temp;
                    dir="D";
                    tempx=x;
                    tempy=y+1;

                }
            }

        }
        if(y!=0){
             if(matrix[x][y-1]==1){
                temp= ((n-1)-(x+1)) + ((n-1)-(y-1));
                if(h>temp){
                    h=temp;
                    dir="U";
                    tempx=x;
                    tempy=y-1;

                }
            }

        }


        cout<<dir;
        matrix[x][y]=0;
        movimientos(matrix,tempx,tempy,n);


    }

}

int main(){ //O(n^2)
    int n;
    cin>>n;

    vector<vector<int> > matrix ( n , vector<int> (n));

    //O(n^2)
    for( int i =0; i<n;i++){
        //O(n)
        for (int j=0; j<n; j++){
            cin>>matrix[j][i];

        }
    }


    movimientos(matrix,0,0,n); //O(n^2)
    cout << endl;




    return 0;

}

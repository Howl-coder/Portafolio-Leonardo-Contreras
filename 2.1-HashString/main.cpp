#include<iostream>
#include <vector>
#include <fstream>
using namespace std;

void hashing(vector<vector<char> > &matriz,int n,int b,string text){
    //O(n^2)


    int indexT=0;
    int sum;
    for(int x=0; x<b;x++){
        for(int y=0; y<n;y++){
            if(indexT<text.length()){

                matriz[x][y]=text.at(indexT);
                indexT++;

            }
            else{

                matriz[x][y]=n;

            }
        }
    }



    int array[n];
    for(int y=0; y<n;y++){
        sum=0;
        for(int x=0;x<b;x++){
            sum=sum+matriz[x][y];



        }
        array[y]=sum%256;
    }

    for (int i = 0; i < n; i++) {
        cout << hex<<array[i];
    }
    cout << endl;

}

int main(){
// compeljidad total O(n^3)
    int n;
    fstream newfile;
    string text = "";
    string temp;
    newfile.open("text.txt",ios::in);
    if (newfile.is_open()){
      getline(newfile, temp);
      text = text + temp;

    }
   newfile.close();

    do{
        cin>>n;
    }
    while(n%4!=0||n<16 || n>64);



    int b;
    if(text.length()%n!=0){
        b=text.length()/n+1;

    }
    else{

        b=text.length()/n;
    }
    vector<vector<char> > matriz( b , vector<char> (n));



    hashing(matriz,n,b,text);



    return 0;
}

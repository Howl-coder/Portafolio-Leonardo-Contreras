#include<iostream>
#include<vector>
#include <fstream>
using namespace std;


void print_vector(vector<string> &V)
{
    for (int i=0; i<V.size();i++){
        cout<<V.at(i)<<endl;
    }
}

void comparar(vector<string> &temp){
    int i=0;
    int j=0;
    int pos=0;
    int n=temp.size();
    int final[n];
  //O(n^2)
    for(j;j<temp.size();j++){



        i=j-1;
        if(j==0){

            final[j]=1;


        }

        else{
            pos=0;
            for(i;i>=0;i--){




                if(temp[i]>temp[j]){

                    final[i]=final[i]+1;


                }

                else if(temp[i]<temp[j]){


                    if(pos<final[i]){
                        pos=final[i];
                    }

                }

                if(i==0){

                    final[j]=pos+1;


                }



            }


        }




    }

    for(int x=0;x<n;x++){
        cout<<final[x]<<endl;
    }


}
int main(){

   string s;
   cin>>s;

    vector<char> v(s.begin(), s.end());


    vector<string>temps;
    for(int i=0;i<v.size();i++){

        string temp= "";
        for(int j=i;j<v.size();j++){
            temp=temp+v[j];



        }
        temps.insert(temps.begin(),temp);


    }

    print_vector(temps);
    comparar(temps);
}

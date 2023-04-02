#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &x){
    int i, j;
    int n= x.size();


    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (x[j] > x[j + 1]){
                swap(x[j],x[j+1]);
             

            
            }
        }
    }
}

int  subsets(vector<int> &arr,vector<int> &v,int s){
    int sum=0;
    vector<int> temp;
    int ts;
    for(int i=0; i<arr.size();i++){
        ts=0;
        temp.erase(temp.begin(),temp.end());
        if(arr[i]<s){
            temp.push_back(arr[i]);
            ts+=arr[i];
            //cout<<ts<<endl;
            for(int j=i+1; j<arr.size();j++){
                if(arr[j]+ts<=s){
                    ts+=arr[j];
                    //cout<<ts<<endl;
                    temp.push_back(arr[j]);
                }

            }

        }
        else if(arr[i]==s){
            temp.push_back(arr[i]);
            ts+=arr[i];


        }
        /*for(int u=0;u<temp.size();u++){
            cout<<temp[u]<<" ";
        }*/
        if(ts>sum){
            sum=ts;
            v.erase(v.begin(),v.end());
            v.insert(v.end(), temp.begin(), temp.end());

        }
    }

    return sum;
}
int main(){
    vector<int> num;
    int n;
    int p;
    cin>>n;
    for(int i =0; i<n;i++){
        cin>>p;
        num.push_back(p);
    }
    vector<int> vx;
    vector<int> vy;
    int sumT =0 ;
    vector<int> vt;
    int temp;
    vector<int> t;
    int sumx =0;
    int sumy=0;
    int s;
    cin>>s;
    vector<int> x (num.begin(), num.begin() + num.size()/2);
    vector<int> y (num.begin() + num.size()/2, num.end());
    sumx=subsets(x,vx,s);
    sumy=subsets(y,vy,s);

    if(sumx>sumy){
        sumT=sumx;
        vt.insert(vt.end(),vx.begin(),vx.end());
    }
    else{
        sumT=sumy;
        vt.insert(vt.end(),vy.begin(),vy.end());
    }
    bubbleSort(vy);
    
    int j=0;
    temp=sumT;
    while(vy[j]+temp<=s){
        temp+=vy[j];
        t.push_back(vy[j]);
        j++;
    }
    if(temp>sumT){
        sumT=temp;
        vt.erase(vt.begin(),vt.end());
        vt.insert(vt.end(),t.begin(),t.end());
    }
    
   

   for(int i=0;i<vx.size();i++){
        int j=0;
        temp=0;
        t.erase(t.begin(),t.end());
        
        if(vx[i]<s){
            temp+=vx[i];
            t.push_back(vx[i]);
            while(vy[j]+temp<=s){
                temp+=vy[j];
                t.push_back(vy[j]);
                j++;
            }
        
        }

        if(temp>sumT){
            sumT=temp;
            vt.erase(vt.begin(),vt.end());
            vt.insert(vt.end(),t.begin(),t.end());
        }
        
   }

   cout<<"La suma maxima del subconjunto es "<<sumT<<", el cual se obtiene de la suma de ";
   for(int i=0; i<vt.size();i++){
        cout<<vt[i]<<" ";
   }
   cout<<endl;


}
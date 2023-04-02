#include <iostream>
using namespace std;

void imprimir(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}
void merge(int *array, int l, int m, int r) {//O(nlog(n))
   int i;
   int j;
   int k;
   int left; 
   int right;

   left = m-l+1; 
   right = r-m;
   int larr[left];
   int rarr[right];
   for(i = 0; i<left; i++)
      larr[i] = array[l+i];
   for(j = 0; j<right; j++)
      rarr[j] = array[m+1+j];
    i = 0; 
    j = 0;
    k = l;
 
   while(i < left && j<right) {
    
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<left) {       
      array[k] = larr[i];
      i++; 
      k++;
   }
   while(j<right) {     
      array[k] = rarr[j];
      j++; 
      k++;
   }
}

void mergeSort(int *array, int left, int right) { 
   int mid;
   if(left < right) {
      int mid = left+(right-left)/2;
      // Sort first and second arrays
      mergeSort(array, left, mid);
      mergeSort(array, mid+1, right);
      merge(array, left, mid, right);
   }
}

int main(){
    int n;
    cout<<"Ingrese tamaño de arreglo"<<endl;
    cin>>n;
    int arr[n];
    int k;
    cout<<"ingrese valores del arreglo"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];

 
    }
    mergeSort(arr, 0, n-1); 
    imprimir(arr, n);    //(n-1) for last index
}
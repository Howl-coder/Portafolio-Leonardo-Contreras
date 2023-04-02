#include <iostream>
using namespace std;

struct Node{
  char letra;
  struct Node *hijo;
  struct Node *sig;
};

void insertar(struct Node ** root,char letra){
    Node * temp = new Node;
    temp->letra=letra;
    temp->hijo= NULL;
    temp->sig= NULL;
    (*root)=temp;
}
void insertar_sig(struct Node * root,char letra){
  Node * temp = new Node;
  temp->letra=letra;
  temp->hijo= NULL;
  temp->sig= NULL;
  root->sig=temp;
}

void insertar_hijo(struct Node * root, char letra){
  Node * temp = new Node;
  temp->letra=letra;
  temp->hijo= NULL;
  temp->sig= NULL;
  root->hijo=temp;
}

bool buscar(struct Node * nodo, string palabra){ //O(n)
  for(int i=0; i<palabra.length();i++){
    while(nodo->sig!= NULL && nodo->letra != palabra[i]){
      nodo=nodo->sig;
    }
    if(nodo->letra==palabra[i]){
      if(nodo->hijo== NULL){
        if(i==palabra.length()-1){
          return true;
        }
        else{
          return false;
        }
      }
      else{
        nodo=nodo->hijo;
      }
    }
    else{
      return false;
    }
  }
  return true;
}

void imprimir(struct Node * nodo){
  if (nodo == NULL){
    return;
  }

  cout << nodo->letra << " ";
  imprimir(nodo->hijo);
  imprimir(nodo->sig);
}

int main(){ //O(n^3)
  int n;
  string palabra;
  struct Node * head = NULL;

  cin>>n;
  for (int j=0; j<n; j++){ //O(n)
    cin>>palabra;
    struct Node *nodo = head;

    int i = 0;
    if(nodo == NULL){
      insertar(&head,palabra[i]);
      struct Node *nodo = head;
      i++;

      while(i < palabra.length()){
        insertar_hijo(nodo,palabra[i]);
        nodo=nodo->hijo;
        i++;
      }
    }
    else{
      while(i < palabra.length()){
        while(nodo->sig != NULL && nodo->letra != palabra[i]){
          nodo=nodo->sig;
        }
        if(nodo->letra != palabra[i]){
          insertar_sig(nodo,palabra[i]);
          nodo=nodo->sig;
          i++;

          while(i < palabra.length()){
            insertar_hijo(nodo,palabra[i]);
            nodo=nodo->hijo;
            i++;
          }
        }
        else{
          if(nodo->hijo == NULL){
            i++;
            while(i<palabra.length()){
              insertar_hijo(nodo,palabra[i]);
              nodo=nodo->hijo;
              i++;
            }
          }
          else{
            i++;
            nodo=nodo->hijo;
          }
        }
      }
    }
  }

  struct Node *nodo = head;
  imprimir(nodo);
  cout << endl;

  int m;
  string busqueda;
  cin>>m;
  for (int i=0; i<m; i++){ //O(n)
    struct Node *nodo = head;
    cin>>busqueda;
    cout<<buscar(nodo,busqueda)<<endl;
  }

  return 0;
}

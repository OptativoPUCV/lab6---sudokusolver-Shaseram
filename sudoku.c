#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int arrayFila[10], arrayCol[10], arraySub[10];
  
  for(int i = 0 ; i < 9 ; i++) {
    for(int x = 0 ; x < 10 ; x++) {
      arrayFila[x] = 0;
      arrayCol[x] = 0;
      arraySub[x] = 0;
    }
    
    for(int j = 0 ; j < 9 ; j++) {
      if(arrayFila[n->sudo[i][j]] == 1) {
        return 0;
      } else arrayFila[n->sudo[i][j]] = 1;

      if(arrayCol[n->sudo[j][i]] == 1) {
        return 0;
      } else arrayCol[n->sudo[j][i]] = 1;
      
      int k = 3*(i/3) + j/3;
      int p = 3*(i%3) + j%3;

      if(arraySub[n->sudo[k][p]] == 1) {
        return 0;
      } else arraySub[n->sudo[k][p]] = 1;
    }
  }
 

  
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();

  for (int p = 1 ; p <= 9 ; p++) {
    Node* nodoAd = copy(n);
    int validar = 0;
    for (int i = 0 ; i < 9 ; i++) {
      for (int j = 0 ; j < 9 ; j++) {
        if (n->sudo[i][j] == 0 && validar == 0) {
          nodoAd->sudo[i][j] = p;
          validar = 1;
        }
      }
    }

    if(validar == 1) pushBack(list, nodoAd);

  }

  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
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
  int *arrayFila, *arrayCol, *arraySub;
  arrayFila = (int*) calloc(10,sizeof(int));
  arrayCol = (int*) calloc(10,sizeof(int));
  arraySub = (int*) calloc(10,sizeof(int));
  
  int validar = 0;
  for(int i = 0 ; i < 9 ; i++) {
    for (int j = 0 ; j < 9 ; j++) {
      if(arrayFila[n->sudo[i][j]] == 1) {
        validar++;
        break;
      } else {
        arrayFila[n->sudo[i][j]] = 1;
      }
    }
    free(arrayFila);
  }
  
  for(int j = 0 ; j < 9 ; j++) {
    for(int i = 0 ; i < 9 ; i++) {
      if(arrayCol[n->sudo[i][j]] == 1) {
        validar++;
        break;
      } else {
        arrayCol[n->sudo[i][j]] = 1;
      }
    }
    free(arrayCol);
  }

 
  for(int k = 0 ; k < 9 ; k++) {
    for(int p = 0 ; p < 9 ; p++) {
      int i = 3*(k/3) + (p/3);
      int j = 3*(k%3) + (p%3);
      if(arraySub[n->sudo[i][j]] == 1) {
        validar++;
        break;
      } else {
        arraySub[n->sudo[i][j]] = 1;
      }
    }
  }
  
  if(validar == 0) {
    return 1;
  } else return 0;

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
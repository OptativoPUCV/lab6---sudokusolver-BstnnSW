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
   int i, k;
   int filas_check[9][10] = {0}; 
   int cols_check[9][10] = {0}; 
   int subgrid_check[9][10] = {0}; 

   for(i = 0; i < 9; i++){
      for(k = 0; k < 9; k++){
         int num = n->sudo[i][k];
         if(num == 0) continue; 
         if(filas_check[i][num] || cols_check[k][num] || subgrid_check[(i / 3) * 3 + (k / 3)][num]){
            return 0; 
         }
               
         filas_check[i][num] = 1;
         cols_check[k][num] = 1;
         subgrid_check[(i / 3) * 3 + (k / 3)][num] = 1;
         }
      }

   return 1; 
}
   


List* get_adj_nodes(Node* n){
   
    List* list=createList();
    
    int fila = -1, col = -1;
    for (int i = 0; i < 9; i++) {
      for (int k = 0; k < 9; k++) {
         if(n->sudo[i][k] == 0) {
            fila = i;
            col = k;
            break;
         }
      }
      if (fila != -1) break; 
    }

    
    if (fila == -1) {
       return list;
   }
    // Generar nodos adyacentes cambiando el valor de la casilla vacía por números del 1 al 9
    for (int num = 1; num <= 9; num++) {
        // Crear una copia del nodo original
        Node* adj_node = copy(n);
        // Asignar el número válido a la casilla vacía
        adj_node->sudo[fila][col] = num;
        // Verificar si el nodo adyacente es válido
        if(is_valid(adj_node)){
            // Agregar el nodo adyacente a la lista solo si es válido
           pushBack(list, adj_node);
        } else {
            // Liberar memoria si el nodo no es válido
            free(adj_node);
        }
    }

    return list;
    return list;
}


int is_final(Node* n){
   for(int i = 0; i < 9; i++){
      for (int k = 0; k < 9; k++){
         if(n->sudo[i][k] == 0){
            return 0; 
         }
      }
   }
   return 1; 
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
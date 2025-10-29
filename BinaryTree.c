/*/Inserts a sequence of integers into a Max-Heap stored in an array - void insert(int item)
Prints the heap after each insertion - void showHeap(void)
Removes the maximum element (the root) K times, reheapifies downward each time, and prints the heap after each removal - int removeMax(void) & void reHeapDown(int i)
Provides a function to print each node with its left/right children (using indices) to reinforce the array-as-tree mapping. ???/*/

#include <stdio.h>
#include <stdlib.h>

#define MAXIMOTAMAÑO 20
int treeNodes[MAXIMOTAMAÑO];
int last = 0;

//1.-
void insert(int item);
void reHeapUp(int index);
void reHeapDown(int i);
int removeMax(void);
void showHeap(void);

  //INSERTAR
  void insert(int item) {
      treeNodes[last] = item;
      reHeapUp(last);
      last++;
      showHeap();
  }

    //REAJUSTA
      void reHeapUp(int index) {
          int i = index;
          int iPrnt = (i - 1) / 2;
      
          while (i > 0 && treeNodes[i] > treeNodes[iPrnt]) {
              int aux = treeNodes[i];
              treeNodes[i] = treeNodes[iPrnt];
              treeNodes[iPrnt] = aux;
      
              i = iPrnt;
              iPrnt = (i - 1) / 2;
          }
      }

  //RE-AJUSTA HACIA ABAJO
void reHeapDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < last && treeNodes[left] > treeNodes[largest])
        largest = left;
    if (right < last && treeNodes[right] > treeNodes[largest])
        largest = right;

    if (largest != i) {
        int aux = treeNodes[i];
        treeNodes[i] = treeNodes[largest];
        treeNodes[largest] = aux;
        reHeapDown(largest);
    }
}

//ELIMINA EL MAXIMO
int removeMax(void) {
    if (last == 0) {
        printf("Heap vacío.\n");
        return -1;
    }

    int maxItem = treeNodes[0];
    treeNodes[0] = treeNodes[last - 1];
    last--;
    reHeapDown(0);
    showHeap();
    return maxItem;
}

// -----------------------------
// Mostrar el heap nodo e hijos
// -----------------------------
void showHeap() {
    for (int i = 0; i < last; i++) {
        printf("\nNode: %d", treeNodes[i]);

        int li = 2 * i + 1;
        int ri = 2 * i + 2;

        if (li < last)
            printf("\n\tLeft Node: %d", treeNodes[li]);
        else
            printf("\n\tLeft Node: (ninguno)");

        if (ri < last)
            printf("\n\tRight Node: %d", treeNodes[ri]);
        else
            printf("\n\tRight Node: (ninguno)");
    }
    printf("\n");
}

//PRINCIPAL
int main() {
    // Insertar elementos
    insert(10);
    insert(30);
    insert(20);
    insert(50);
    insert(40);
    insert(60);

    // Eliminar máximo 3 veces
    printf("\nEliminando máximo 3 veces:\n");
    removeMax();
    removeMax();
    removeMax();

    return 0;
}


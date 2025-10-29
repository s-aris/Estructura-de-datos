/*/Inserts a sequence of integers into a Max-Heap stored in an array - void insert(int item)
Prints the heap after each insertion - void showHeap(void)
Removes the maximum element (the root) K times, reheapifies downward each time, and prints the heap after each removal - int removeMax(void) & void reHeapDown(int i)
Provides a function to print each node with its left/right children (using indices) to reinforce the array-as-tree mapping. ???/*/

//Insert integer
#include <stdio.h>
#include <stdlib.h>

#define MAXIMOTAMAÑO 9
int treeNodes[MAXIMOTAMAÑO];

int last=0;

  //2.-
  void insert(int item){
    treeNodes[last]=item;
    reHeapUp(last);
    last++;
  }

  insert(1)
  insert(2)
  insert(3)
  insert(4)
  insert(5)
  insert(6)
  insert(7)
  insert(8)
  insert(9)
  insert(10)

    //3.-to compare and organize
    void reHeapUp(int index){
      int i = index;
        int iPrnt = (i-1)/2;
        while(iPrnt >= 0){
        if(treeNodes[i] > treeNodes[iPrnt]) {
          //swap
          int aux = treeNodes[iPrnt];
          treeNodes[iPrnt] = treeNodes[index];
          treeNodes[index] = aux;
          i = iPrnt;
          iPrnt = (i-1)/2;
          }else
          break;
     }
  }

#include <stdio.h>
#include <string.h>

#define MAXSIZE 10
int treeNodes[MAXSIZE];
int last=0;

//1.Organiza hacia arriba 
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
      }else{
      break;
      }
      }}

void insert(int item){
  treeNodes[last]=item;
  reHeapUp(last);
last++;
}

void showHeap(){
for(int i = 0; i <= last; i++){
printf(“\nNode: %d”, treeNodes[i]);
int li = 2*i + 1;
int ri = 2*i + 2;
printf(“\n\t Left Node: %d”, treeNodes[li]);
printf(“\n\t Right Node: %d”, treeNodes[ri]);
}
}



//PRINT
void showHeap(){
for(int i = 0; i <= last; i++){
printf(“\nNode: %d”, treeNodes[i]);
int li = 2*i + 1;
int ri = 2*i + 2;
printf(“\n\t Left Node: %d”, treeNodes[li]);
printf(“\n\t Right Node: %d”, treeNodes[ri]);
}
}

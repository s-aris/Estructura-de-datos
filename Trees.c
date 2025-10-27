#include <stdio.h>

#define MAXSIZE 15  

int main() {
    //1.Llenar el arbol
    int treeNodes[MAXSIZE] = {
        10,   
        50,   
        90,   
        88,   
        100,  
        78,   
        0,   
        99,   
        7,    
        89,   
        20,   
        67,   
        76,   
        -1,   
        -1    
    };

    // 2)Imprimir el arbol
    printf("Mapping of the binary tree as an array:\n\n");
    for (int i = 0; i < MAXSIZE; i++) {
        printf("Index %2d → %3d\n", i, treeNodes[i]);
    }

    return 0;
}

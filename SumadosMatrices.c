#include <stdio.h>
#include <stdlib.h>


int main()
{
    //Allocate two matrix of size rowsxcols
    int rows, cols;
    
    printf("Ingrese el numero de filas:");
    scanf("%d",&rows);
    printf("Ingrese el número de columnas:");
    scanf("%d",&cols);
    
        //Save memory for matrix one block
         int *A = (int*)malloc((size_t)rows * (size_t)cols * sizeof(int));
         int *B=(int*)malloc((size_t)rows*(size_t)cols*sizeof(int));
         int *C=(int*)malloc((size_t)rows*(size_t)cols*sizeof(int));
         
        //Fill the matrix 
        printf("Ingrese los valores para llenar la matriz:");
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols;j++){
                scanf("%d",&A[i*cols + j]);
            }
        }
        
       
        //Free memory
        free(A);
        free(B);
        free(C);

    return 0;
}

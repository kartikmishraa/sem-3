/*
    ----------------------------------------------------
    Program to represent a NxN sparse matrix with random 
    non zero elements with appropriate density
    ----------------------------------------------------
*/
/*
    NOTE: % of non zero elements is known as DENSITY of a sparse matrix
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// matrixGen() is passed a sparse matrix, which is then filled by non zero elements after scanning 
// density of the sparse matrix from the user

int matrixGen(int *matrix, int n)
{
    // Scanning density of sparse matrix 
        
        int percent;
        printf("\nEnter density of sparse matrix(in \%): ");
        scanf("%d", &percent);

        int pr = (((n * n) * percent) / 100);    // int pr refers to no. elements to be made non zero
        
        int limit = 0;         // int limit will be used to break out of the while loop in ln 37 

    // Filling sparse matrix with appropriate number of non zero elements

        srand(time(0));
        while (limit < pr)
        {
            int i = rand() % (n * n);
            matrix[i] = rand(); 
            limit++;
        }
}

/* Utility function to print a matrix of order NxN */

int matrixPrint(int *matrix, int n)
{       
    printf("\nMatrix is : - \n");
    for (int i = 0; i < n * n; i++)
    {
        printf("%d         ", matrix[i]);
        if ((i + 1) % n == 0)
            printf("\n");
    }
}

int main()
{
    // Scanning order of matrix and initializing sparse matrix of size NxN dynamically 
        
        int n;
        printf("\nEnter order of the sparse matrix: ");
        scanf("%d", &n);

        int *matrix = (int *)calloc(n * n, sizeof(int));      

    matrixGen(matrix, n);   // calling function to fill the sparse matrix with non zero elements

    matrixPrint(matrix, n); // calling function to print the sparse matrix

    free(matrix);
    
    return 0;
}

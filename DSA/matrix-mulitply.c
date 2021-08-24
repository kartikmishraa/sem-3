/*
    ------------------------------------------------------
    Write a C program to compute matrix multiplication.
    Two matrices need to be generated using dynamic memory 
    allocation and user defined function. 
    ------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

/* Function to multiply 2 matrices passed as arguments */

void matrixMultiply(int **arr1, int **arr2, int m, int n, int a, int b)
{
    // Condition to check if the columns of 1st matrix and rows and of 2nd matrix are equal   
        if(n != a)
        {
            printf("\nThe matrices cannot be multiplied!");
            exit(0);
        }

    // Product matrix, dynamically allocated to store the product of the 2 matrices
        int **product = (int **)malloc(m * sizeof(int *));
        for(int i = 0; i < m; i++)
            product[i] = (int *)malloc(b * sizeof(int));

    // Computing the product of the 2 matrices and storing in product matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < b; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum = sum + arr1[i][k] * arr2[k][j];
                }
                product[i][j] = sum;
            }
        }   

    // Printing product of 2 matrices
        printf("\n-------------Product of the matrices------------------\n");
        printf("\nProduct is: - \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("%d  ", product[i][j]);
            }
            printf("\n");
        }
    
    // freeing the pointer
        free(product);
}

/* Function to generate 2 matrices and then call matrixMultiply() function */

void matrixGen()
{
    int m, n, a, b; 

    printf("\n-----------------MATRIX GENERATOR---------------------\n"); 
    
    // Scanning order of matrix 1
        printf("For a matrix of order MxN, enter m: ");
        scanf("%d", &m);
    
        printf("\nEnter n: ");
        scanf("%d", &n);
    
    // Dynamically allocating matrix 1 using double pointer
        int **arr1 = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++)
            arr1[i] = (int *)malloc(n * sizeof(int)); 
    
    // Scanning elements of matrix 1
        printf("\nEnter elements for array 1: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        
        }

    // Scanning order of matrix 2
        printf("\nFor a matrix of order AxB, enter a: ");
        scanf("%d", &a);
    
        printf("\nEnter b: ");
        scanf("%d", &b);

    // Dynamically allocating matrix 2 using double pointer
        int **arr2 = (int **)malloc(a * sizeof(int *));
        for (int i = 0; i < a; i++)
        arr2[i] = (int *)malloc(b * sizeof(int)); 
    
    // Scanning elements of matrix 2 
        printf("\nEnter elements for array 2: \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                scanf("%d", &arr2[i][j]);  
            }
        
        }

    // Printing matrix 1
        printf("\nMatrix 1: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d  ", arr1[i][j]);
            }
            printf("\n");
        }
    
    // Printing matrix 2
        printf("\nMatrix 2: \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("%d  ", arr2[i][j]);
            }
            printf("\n");
        }

    // Calling function to compute and display the products of the entered matrices
        matrixMultiply(arr1, arr2, m, n, a, b);

    // Freeing pointers
        free(arr1);
        free(arr2);
}

int main()
{
    matrixGen();
    return 0;
}
// end of program

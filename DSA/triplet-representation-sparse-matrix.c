/*
    ------------------------------------
    WAP to represent a sparse matrix
    efficiently using the triplet format
    ------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/* Utility function to print any 2D array (matrix) of order RxC */
    void matrixPrint(int **matrix, int r, int c)
    {       
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("%d   ", matrix[i][j]);
            }
            printf("\n");
        }
    }

/* Utility function to generate a sparse matrix of definite density 
    -> Function accepts row and column and dynamically allocates memory for a RowXColumn 2D array 
    -> then density is given by the user, and the function randomly fills the sparse matrix with 
       with non zero elements and returns the sparse matrix.
*/
    int **matrixGen(int row, int column)
    {
        // Dynamically allocating a 2D array
            int **matrix = (int **)calloc(row, sizeof(int *));
            for (int i = 0; i < row; i++)
                matrix[i] = (int *)calloc(column, sizeof(int));
    
        srand(0);

        //Scanning density from the user
            int density;   
            printf("\nEnter density of the sparse matrix(in \%): ");
            scanf("%d", &density);
    
        int no_of_elements = (((row * column) * density) / 100); // calculating no. of non zero elements to be filled
        
        int limit = 0;       // will be used to break out of the while loop in ln 52 

        // Filling sparse matrix with appropriate number of non zero elements

            srand(time(0));
            while (limit < no_of_elements)
            {
                int i = rand() % row;
                int j = rand() % column;
                matrix[i][j] = rand(); 
                limit++;
            }

        return matrix;
    } // end of matrixGen()


/*  Function represent a sparse matrix passed as argument in triplet format
     -> accepts a sparse matrix, no. of rows & columns as arguments
     -> dynamically allocates a 2D array to store triplet representation 
     -> print the sparse matrix and the triplet representation using matrixPrint() function
*/
    void matrixRep(int **matrix, int row, int column)
    {
        // Computing the number of non zero elements in the sparse matrix
            int size = 0;
            for (int i = 0; i < row; i++)
            {   
                for (int j = 0; j < column; j++)
                {
                    if(matrix[i][j] != 0)
                        size++;
                }
            }
    
        // Dynamically allocating memory for a 2D array to store the triplet representation
            int **tripletRep = (int **)malloc(3 * sizeof(int *));
            for (int i = 0; i < 3; i++) 
            {
                tripletRep[i] = (int *)malloc(size * sizeof(int));
            }

        // Initializing tripletRep[][] so as to store the triplet representation of matrix[][]
            int k = 0;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    if(matrix[i][j] != 0)
                    {
                        tripletRep[0][k] = i;
                        tripletRep[1][k] = j;
                        tripletRep[2][k] = matrix[i][j]; 
                        k++;
                    }
                }
            }

        // Printing the Sparse matrix along with its Triplet Representation
            printf("\n\n------------------Sparse Matrix---------------------\n");
            matrixPrint(matrix, row, column);

            printf("\n------------------Triplet Representation---------------------\n");
            matrixPrint(tripletRep, 3, size);

    }   // end of matrixRep() 

int main()
{
    int r, c;

    printf("\nEnter number of rows: ");
    scanf("%d", &r);

    printf("\nEnter number of columns: ");
    scanf("%d", &c);

    matrixRep(matrixGen(r, c), r, c);

    return 0;
}

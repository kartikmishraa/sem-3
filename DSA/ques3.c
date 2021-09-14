#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct node
{
    int row, column, data;
    struct node* next;
};

// Function to print a matrix
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


// Function to randomly create a sparse matrix
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
    
    int nonZero = ((row * column) * density) / 100; // calculating no. of non zero elements to be filled
        
    int limit = 0;

    // Filling sparse matrix with appropriate number of non zero elements

        srand(time(0));
        while (limit < nonZero)
        {
            int i = rand() % row;
            int j = rand() % column;
            matrix[i][j] = rand(); 
            limit++;
        }

        printf("\n Sparse matrix is: \n");

        matrixPrint(matrix, row, column);

        printf("\n");

    return matrix;
} // end of matrixGen()


// Function to create triplet representation using linked list
void matrixRep(int **sparse, int row, int column)
{
    struct node* head = NULL; 

    // iterating through all the elements of the sparse matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                // for non-zero elements 
                    if (sparse[i][j] != 0)
                    {
                        // creating new node and storing data  
                            struct node* newNode = (struct node*)malloc(sizeof(struct node));

                            newNode->row = i; 
                            newNode->column = j;
                            newNode->data = sparse[i][j];

                        // pushing the new node in to the linked list
                            if (head == NULL)
                            {
                                head = newNode;
                                newNode->next = NULL;
                            }

                            else
                            {
                                newNode->next = head;
                                head = newNode;
                            }
                    }
            }
        }

    // printing the triplet representation
        
        printf("\n\n-----Triplet-Rep-----\n");

        struct node* temp = head;

        for(temp; temp != NULL; temp = temp->next)
        {
            printf("\n\ndata: %d (%d,%d)", temp->data, temp->row, temp->column);
        }

} // end of matrixRep()

int main()
{
    int r, c;

    printf("\nenter no. of rows of sparse matrix: ");
    scanf("%d", &r);

    printf("\nenter no. of columns of sparse matrix: ");
    scanf("%d", &c);

    matrixRep(matrixGen(r, c), r, c);    

    return 0;
} // end of main()

// end of program
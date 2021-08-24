/*
    ----------------------------
    WAP to implement addition of 
    two polynomials using array
    ----------------------------
*/

#include<stdio.h>
#include<stdlib.h>

// Function to return greater of 2 numbers
int max(int a, int b){
    return a > b ? a : b;
}

void printPoly(int *poly, int deg);     // Function to print a polynomial of degree 'deg'

void scanPoly(int *poly, int deg);      // Function to scan a polynomial of degree 'deg'

int addPoly(int *A, int *B, int degA, int degB);    // Function to add two polynomials and print the result

int main()
{
    int deg1, deg2;     // Variables to store degree of polynomials

    // Scanning degree of the two polynomials

        printf("\nEnter highest degree of poly 1: ");
        scanf("%d", &deg1);

        printf("\nEnter highest degree of poly 2: ");
        scanf("%d", &deg2);

    // Initializing the two polynomials using Dynamic memory
        
        int *poly1 = (int*)calloc(max(deg1, deg2), sizeof(int));
        int *poly2 = (int*)calloc(max(deg1, deg2), sizeof(int));

    // Scanning polynomial elements
    
        printf("\nEnter coeff of poly 1: \n");
        scanPoly(poly1, deg1);
    
        printf("\nEnter coeff of poly 2: \n");
        scanPoly(poly2, deg2);
    
    // Calling function to add the two polynomials and printing the result

        addPoly(poly1, poly2, deg1, deg2);

    // freeing the pointers

        free(poly1); 
        free(poly2);

    return 0;
}   // end of main()

void printPoly(int *poly, int deg)
{
        for (int i = 0; i <= deg; i++)
        {
            if(i == deg)
                printf(" %dx^%d", poly[i], i);
            else
                printf(" %dx^%d +", poly[i], i);
        }
}

void scanPoly(int *poly, int deg)
{
    for (int i = 0; i <= deg; i++)
        {
            printf("\nx^%d: ", i);
            scanf("%d", &poly[i]);
        }
}

int addPoly(int *A, int *B, int degA, int degB)
{
    // Dynamically allocating memory to an array to store the sum of 2 polynomials
        int *C = (int *)calloc(max(degA, degB), sizeof(int));

    // Printing the two polynomials to be added

        printf("\npoly A: \n");
        printPoly(A, degA);

        printf("\npoly B: \n");
        printPoly(B, degB);

    // Storing the sum of A and B in C and printing the result

        for (int i = 0; i <= max(degA, degB); i++)
            C[i] = A[i] + B[i];

        printf("\n\nSum: -\n");
        printPoly(C, max(degA, degB));

    free(C);
}
// end of program 

/* 
    STACK IMPLEMENTATION using ARRAY in C 
    In the program I have declared a stack using array and created a menu driven program to perform 
    stack operations such as push, pop, check empty, and display. 
*/

#include<stdio.h>
#define MAX 100

/* Function prototypes */
int empty_check(int);
void display(int*, int);
void push(int*, int*);
void pop(int*, int*);

/* Function to print Menu */
void menu()
{
    printf("\n\n----Menu----\n");
    printf("1. Empty Check\n");
    printf("2. Display\n");
    printf("3. Push\n");
    printf("4. Pop\n");
    printf("0. Exit\n");
    printf("\nenter choice...");
}

int main()
{
    // creating the stack
      int stack[MAX], top = -1;   // top = -1 indicates that stack is empty!
    
    int choice;

    do{
        menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(empty_check(top))
                  printf("\nStack is empty...\n");

                else 
                  printf("\nStack is not empty...\n");
                break;
            
            case 2:
                display(stack, top);
                break;

            case 3:
                push(stack, &top);
                break;

            case 4:
                pop(stack, &top);
                break;
         
            case 0:
                printf("\nexiting the program...\n");
                exit(0);
         
            default:
                printf("\nenter valid option!\n");
        }
    } while(choice != 0);
 
    return 0;
} // end of main()


/* Function returns true if the stack is empty */
int empty_check(int top)
{
    if(top == -1)
      return 1;
 
    else 
      return 0;
}

/* Function to print the stack */
void display(int *stack, int top)
{
    if(empty_check(top))
      printf("\nStack Underflow (empty)\n");
  
    else
    {
        printf("\nDisplaying stack: -\n");
     
        for(int i = top; i >= 0; i--)
          printf("%d  ", stack[i]);
    }
}

/* Function to push an element to the stack */
void push(int *stack, int *top)
{
    if(*top >= MAX)
      printf("\nStack Overflow\n");

    else
    {
        *top = *top + 1;    // *top++ cannot be used, why? i didn't understand this
     
        int num;
     
        printf("\nenter number to be pushed: ");
        scanf("%d", &num);

        stack[*top] = num;
     
        printf("\n'%d' successfully pushed to the stack!", num);
    }
}

/* Function to pop an element from the stack */
void pop(int *stack, int *top)
{
    if(*top == -1)
      printf("\nStack Underflow\n");
 
    else
    {
        printf("\n'%d' successfully popped from the stack!", stack[*top]);
     
        *top = *top - 1;
    }
}

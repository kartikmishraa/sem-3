/* 
    STACK IMPLEMENTATION using LINKED LIST in C 
    In the program I have declared a stack top globally and created a menu driven program to perform 
    stack operations such as push, pop, check empty, and display. 
*/

#include<stdio.h>
#include<stdlib.h>

/* Defining the structure node */
struct node
{
    int val;
    struct node* next;  
} *top = NULL;  // initially stack empty

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

/* Function prototypes */

int empty_check();
void display();
void push(int);
void pop();

// ---------------------------------------

int main()
{   
    int choice;
    
    do 
    {
        menu();
        scanf("%d", &choice);

        int val;

        switch(choice)
        {
            case 1:
                if(empty_check())
                  printf("\nStack is empty...\n");

                else 
                  printf("\nStack is not empty...\n");
                break;
            
            case 2:
                display();
                break;

            case 3:
                printf("\nenter data to be pushed: \n");
                scanf("%d", &val);
         
                push(val);
         
                printf("\n%d successfully pushed to the stack!\n", val);
                break;

            case 4:
                pop();
                break;
         
            case 0:
                printf("\nexiting the program...\n");
                exit(0);
         
            default:
                printf("\nenter valid option!\n");
        }
     
    } while (choice != 0);
    return 0;
}

// fuction to check if stack is empty
int empty_check()
{
    if(top == NULL)
      return 1;

    else 
      return 0;
}

// function to push an element to the stack
void push(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->val = val;

    if(top == NULL)
    {
        top = newNode;
        newNode->next = NULL;
    }

    else
    {
        newNode->next = top;
        top = newNode;         
    }
}

// function to print stack elements 
void display()
{
    if (empty_check(top))
    {
        printf("\nstack underflow!\n");
        return;
    }

    struct node *temp = top;
    for (temp; temp != NULL; temp=temp->next)
        printf("%d -> ", temp->val);

    free(temp);
}

// function to pop (delete) an element from stack top
void pop()
{
    if (empty_check(top))
    {
        printf("\nstack underflow!\n");
        return;
    }

    struct node *temp = top;

    top = top->next;

    printf("\n %d popped out of the stack!\n", temp->val);
    free(temp);
}

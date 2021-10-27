/*
  C program to convert a user inputted infix expression into its 
  equivalent postfix expression and display it. 
*/

#include<stdio.h>
#include<ctype.h>
#define MAX 100

// defining stack and top
  char stack[MAX];
  int top = -1;

// function to push a character onto the stack
  void push(int val)
  {
      if(top == MAX-1)
          printf("\nstack overflow!\n");

      else
          stack[++top] = val;
  }


// function that pops and returns the top of stack
  char pop()
  {
      if(top == -1)
          printf("\nstack underflow!\n");

      else
        return stack[top--];
  }


// function that returns priority of the passed character
  int priority(char x)
  {
      if(x == '(')
          return 0;
    
     else if(x == '+' || x == '-')
         return 1;
    
     else if(x == '*' || x == '/')
         return 2;
    
     return 0;
  }

int main()
{
    char exp[MAX];
    char *ptr = exp, x;

    printf("\nenter infix expression: \n");
    scanf("%s", &exp);
 
    printf("\npostfix:\n");

    while(*ptr != '\0')
    {
        if(isalnum(*ptr))
            printf("%c", *ptr);
        
        else if(*ptr == '(')
            push(*ptr);
        
        else if(*ptr == ')')
            while((x = pop()) != '(')
                printf("%c", x);

        else
        {
            while(priority(stack[top]) >= priority(*ptr))
                printf("%c", pop());
            
            push(*ptr);
        }
        ptr++;
    }

    while(top != -1)
            printf("%c", pop());
            
    return 0;
 
} // end of main()

// end of program

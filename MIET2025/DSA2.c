#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int stack[MAX], top = -1;
int isFull()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
{
    return top == MAX-1 ? 1 : 0;
}
int isEmpty()
{
    return top == -1 ? 1:0;
}
int  push()
{
    if(isFull())
    {
        printf("Stack Overflow !!!!\n");
    }
    else
    {
        int value;
        printf("Enter value:");
        scanf("%d",&value);
        top++;
        stack[top] = value;
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow !!!!\n");
        return INT_MIN;
    }
    else
    {
        int val= stack[top];
        top--;
        return val;
    }
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty !!!!\n");
        return INT_MIN;
    }
    else
    {
        return stack[top];
    }
}
void show()
{
    if(isEmpty())
    {
       printf("Stack empty !!!!\n");
    }
    else
    {
        for(int i=top; i>=0; i--)
        {                          
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    while(1)
    {
        
        
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        int choice , val;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1: 
           push();
           break;
           case 2: 
           val= pop();
           if(val!= INT_MIN)
            printf("%d pop rom the stack!!\n",val);
           break;
           case 3:
           val= peek();
           if(val!= INT_MIN)
           printf("Top element is %d\n",val);
           break;
           case 4:
           show();
           break;
           case 5:
           exit(0);
           break;
           default:
           printf("Invalid Choice!!!!\n");
    }
    printf("\n");
    printf("System pause");
    
}
    return 0;
}

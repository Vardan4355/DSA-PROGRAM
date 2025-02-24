#include<stdio.h>
#include<limits.h>
#define MAX 100
int stack[MAX],top1 =-1,top2 = MAX;
int isstack1empty(){
    return (top1 ==-1)? 1 : 0;
}
int isstack2empty(){
   return (top1 == MAX) ? 1 : 0;
}
int isstack1full(){
    return(top1 == top2-1) ? 1 : 0;
}
int isstack2full(){
    return (top2 == top1 + 1)? 1 : 0;
}
void push_stack1(int data){
    if(isstack1full())
    printf("Stack1 overflow!!!\n");
    else{
        stack[++top1]= data;
        printf("Element Added !!!\n");
    }
}
void push_stack2(int data){
    if(isstack2full())
    printf("Stack2 overflow!!!\n");
    else{
        stack[--top2]= data;
        printf("Element Added !!!\n");
    }
}
void pop_stack1(){
    if(stack1isEmpty()){
        printf("Stack Underflow!!!\n");
        return INT_MIN;
    }
    else{
        int val= stack[top1--];
        printf("%d pop from stack1 !!!\n",val);
    }
}
void pop_stack2(){
    if(stack2isEmpty()){
        printf("Stack Underflow!!!\n");
        return INT_MIN;
    }
    else{
        int val= stack[top2++];
        printf("%d pop from stack2 !!!\n",val);
    }
}
void peek_stack1(){
    if(isstack1Empty())
        printf("Stack1 is empty\n");
    
    else
        printf("Top element of stack-1 is%d\n",stack[top1]);
    
}
int peek_stack2(){
    if(isstack2Empty())
        printf("Stack2 is empty\n");
    
    else{
        printf("Top element of stack-2 is%d\n",stack[top2]);
    }
}
void show_stack1()
{
    if(isstack1Empty())
    {
       printf("Stack1 is empty !!!!\n");
    }
    else
    {
        printf("Stack1 elements are:\n");
        for(int i=top1; i>=0; i--)
        {                          
            printf("%d\n", stack[i]);
        }
    }
}
void show_stack2()
{
    if(isstack2Empty())
    {
       printf("Stack2 is empty !!!!\n");
    }
    else
    {
        printf("Stacke elements are:\n");
        for(int i=top2; i<MAX; i++)
        {                          
            printf("%d\n", stack[i]);
        }
    }
}

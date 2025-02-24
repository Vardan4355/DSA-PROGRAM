#include<stdio.h>
#define MAX 50
#include<limits.h>
int stack[MAX]; top1 =-1; top2 =MAX;
int stack1(Isempty){
    return (top1 == -1)? 1:0;
}
int stack2(Isempty){
    return (top2 == MAX)? 1:0;
}
int stack1(IsFull){
    return (top1 == top2-1)?1:0;
}
int stack2(IsFull){
    return (top2 == top1+1)?1:0;
}
void push_stack1(int data){
           if(Isstack1Full())
           printf("Stack-1 Overflow!!\n");
           else{
           stack[++top1] = data;
           printf("Element Added!!\n");
  }
}
void push_stack2(int data){
    if(Isstack2Full())
    printf("Stack-2 Overflow!!\n");
    else
    {
        printf("Element Added!!\n");
    stack[--top2] = data;
  }
}
void pop_stack1(){
    if(Isstack1empty())
    printf("Stack1 Underflow!!\n");
    else
    printf("%d pop from stack-1\n",stack[top1--]);
}
void pop_stack2(){
    if(Isstack2empty())
    printf("Stack2 Underflow!!\n");
    else
    printf("%d pop from stack-2\n",stack[top2++]);
}
void peek_stack1(){
     if(stack1Isempty())
     printf("Stack1 is empty\n");
     else{
     printf("%d peek from stack-1\n",stack[top1]);
     }
}
void peek_stack2(){
    if(stack2Isempty())
    printf("Stack2 is empty\n");
    else{
    printf("%d peek from stack-2\n",stack[top2]);
    }
}
void show_stack1(){
     if(stack1Isempty())
     printf("Stack1 is empty\n");
     else
     for(int i=top1; i>0; i--){
            printf("%d",stack[i]);
            
     }
}

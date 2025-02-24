#include<stdio.h>
#define MAX 100
int stack[MAX],top1= -1,top2=MAX;
int isStack1Empty(){
    return (top1== -1)? 1:0;
}
int isStack1Full(){
    return (top2==top1+1)? 1:0;
}
void push_stack1(int data){
    if(isStack1Full())
        printf("Stack-1 overflow!!!\n");
        else{
            stack[++top1]=data;
            printf("Element added.\n");
        }
}
void push_stack2(int data){
    if(isStack1Full())
        printf("Stack-2 overflow!!!\n");
        else{
            stack[--top1]=data;
            printf("Element added.\n");
        }
}
void pop_stack1(){
    if(isStack1Empty())
        printf("Stack-1 underflow!!!\n");
        else{
            top1--;
            printf("Element deleted.\n");
        }
}
void pop_stack2(){
    if(isStack2Empty())
        printf("Stack-2 underflow!!!\n");
        else{
            top2--;
            printf("Element deleted.\n");
        }
}
void peek_stack1(){
    if(isStack1Empty())
        printf("Stack is empty!!!\n");
        else{
    printf("Topmost element= %d\n",stack[top1]);
        }}
void peek_stack2(){
    if(isStack2Empty())
        printf("Stack is empty!!!\n");
        else{
    printf("Topmost element= %d\n",stack[top2]);
        }}
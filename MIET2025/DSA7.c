// WAP to check wether the given expression is properly
#include<stdio.h>
#include<string.h>
#include<limits.h>
int checkbalanced(char *str){
    int len = strlen(str), top=-1;
    char stack[len];
    for(int i=0;  i<len; i++){
        char ch = str[i];
        if(ch == '(' || ch =='{' || ch == '[')
        stack[++top] =ch;
        else if(ch == ')' || ch =='}' || ch == ']')
            if(top == -1)
            return 0;
            else if(ch == ')'  && stack[top] != '(')
            return 0;
            else if(ch == '}'  && stack[top] != '{')
            return 0;
            else if(ch == ']'  && stack[top] != '[')
           return 0;
           else 
           top--;
       }
    }
    if(top == -1){
     return 1;
     else
    return 0;
    }
int main(){
    char str[100];
    printf("Enter Expression:");...........................................................................................................................................................................................................................................................................................0
    gets();
    int result = checkbalanced(str);
    if(result == 1)
    printf("ExpressionBalanced!!\n");
    else
    printf("Not Balanced!!\n");
    return 0;
}



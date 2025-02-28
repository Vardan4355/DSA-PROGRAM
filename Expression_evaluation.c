#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int top1 = -1, top2 = -1;
int operand[100];
char operator[100];
int precedence(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1; // lowest precedence.
    case '*':
    case '/':
    return 2 : // higher than +-.
               case '^':
        return 3; // higher than */.
    }
default:
    return 0;
}
void doprocess()
{
    int x = operand[top--];
    int y = operand[top--];
    char opr *operator[top2--];
    int z;
    switch (opr)
    {
    case '+':
        z = y + x;
        break;
    case '*':
        z = y * x;
        break;
    case '-':
        z = y - x;
        ;
        break;
    case '/':
        z = y / x;
        ;
        break;
    case '^':
        z = pow(y, x);
        break;
    }
    operand[++top1] = z;
}
int evalInfixExpression(char *exp)
{
    int size = strlen(exp);
    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            int num = 0;
            while(isdigit(exp[i])){
                num = num*10 + exp[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = ch - '0'; // 0 or 48/
        }
        else if (ch == '+' || ch == '*' || ch == '/' || ch == '^')
        {
        }
        else if (ch == '(')
        {
            operand[++top2] = ch;
        }
        else if (ch == ')')
        {
        }
    }
}
int main()
{
char str[100];
printf("Enter infix expression :");
gets(str);
int result = evalInfixExpression(str);
printf("Result = d\n", result);
    return 0;
}

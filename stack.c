
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

tNodeStack* createStack(int length){
    tNodeStack* stack = (tNodeStack*)malloc(sizeof(tNodeStack));
    stack->oper = (int*)malloc(sizeof(int) * length);

    stack->top=-1;

    return stack;
}

int isEmpty(tNodeStack *stack)
{
    if(stack->top==-1)
    	return(1);
 	else
   		return(0);
}

void Push(tNodeStack *stack, char x)
{
    stack->top=stack->top+1;
    stack->oper[stack->top]=x;
}

char Pop(tNodeStack *stack)
{    
    if (!isEmpty(stack)) {
        return stack->oper[stack->top--];
    } else {
        return '\0';
    }
}

int Top(tNodeStack *p){
    return (p->oper[p->top]);
}

int getPriority(char opr){
    // if(opr=='(')
    //     return(1);
    if(opr=='+'||opr=='-')
        return(1);
    if(opr=='*'||opr=='/')
        return(2);
    if(opr=='^')
        return(3);
    if(opr=='#')
        return(4);
 	else
    	return(-1);
}

int infix_to_postfix(char infix[],char postfix[])
{
    tNodeStack* s = createStack(strlen(infix));
    char x,token;
    int i,j;    //i-index of infix,j-index of postfix
    
    j=0;
 
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];

        if (token == ' ') continue;

        else if (isdigit(infix[i]) || infix[i] == '.') {
            do {
                postfix[j++] = infix[i++];
            } while (isdigit(infix[i]) || infix[i] == '.');
            postfix[j++] = ' ';
            i--;
        }
        
        else if(token=='(')
            Push(s, token);
        
        else if(token==')') {
            while((x=Top(s))!='(' && !isEmpty(s)) {
                postfix[j++]= Pop(s);
                postfix[j++] = ' ';
            }
                    
            if (!isEmpty(s) && Top(s) != '(') {
                return -1;
            } else {
                Pop(s);
            }
        }

        else {
            while(getPriority(token) <= getPriority(Top(s)) && !isEmpty(s))
            {
                x=Pop(s);
                postfix[j++]=x;
                postfix[j++] = ' ';
            }

            if (infix[i] == '-' && isdigit(infix[i-1])) {
                Push(s, '+');
            }

            Push(s,token);
        }
    }
 
    while(!isEmpty(s))
    {
        x=Pop(s);
        postfix[j++]=x;
        postfix[j++]=' ';
    }
 
    postfix[j--]='\0';

    return 0;
}

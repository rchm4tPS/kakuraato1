
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

void createStack(tNodeStack *stack){
    stack->top=-1;
}

int isEmpty(tNodeStack *stack)
{
    if(stack->top==-1)
    	return(1);
 	else
   		return(0);
}

int isFull(tNodeStack *stack)
{
    if(stack->top==MAX-1)
    	return(1);
 	else
    	return(0);
}

void Push(tNodeStack *stack,int x)
{
    if (!isFull(stack)) {
        stack->top=stack->top+1;
        stack->oper[stack->top]=x;
    }
}

int Pop(tNodeStack *stack)
{
    int x = -999;
    
    if (!isEmpty(stack)) {
        x=stack->oper[stack->top];
        stack->top=stack->top-1;
    }

    return(x);
}

int Top(tNodeStack *p){
    return (p->oper[p->top]);
}

int getPriority(char opr){
    if(opr=='(')
        return(1);
    if(opr=='+'||opr=='-')
        return(2);
    if(opr=='*'||opr=='/')
        return(3);
    if(opr=='^'||opr=='#')
        return(4);
 	else
    	return(-1);
}

void infix_to_postfix(char infix[],char postfix[])
{
    tNodeStack s;
    char x,token;
    int i,j;    //i-index of infix,j-index of postfix
    createStack(&s);
    j=0;
 
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))      // check if token is "alphanumeric" character or not
            postfix[j++]=token;
        else
            if(token=='(')
               Push(&s,'(');
        else
            if(token==')')
                while((x=Pop(&s))!='(')
                      postfix[j++]=x;
            else
                {
                    while(getPriority(token)<=getPriority(Top(&s))&&!isEmpty(&s))
                    {
                        x=Pop(&s);
                        postfix[j++]=x;
                    }
                    Push(&s,token);
                }
    }
 
    while(!isEmpty(&s))
    {
        x=Pop(&s);
        postfix[j++]=x;
    }
 
    postfix[j]='\0';
}

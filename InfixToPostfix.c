#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100
struct Stack
{
    char arr[MAX];
    int top; 

};
void init(struct Stack *p)
{   for(int i=0;i<MAX;i++)
        p->arr[i]='\0';

    p->top=-1;
}
int isFull(struct Stack *p)
{
    if(p->top==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct Stack *p)
{
    if(p->top==-1)
        return 1;
    else
        return 0;
}
void push(struct Stack *p,char c)
{   if(isFull(p))
        printf("Array is full\n");
    else
    {
        p->top++;
        p->arr[p->top]=c;
    }
}
char pop(struct Stack *p)
{
    if(isEmpty(p))
        printf("Array is Empty\n");
    else
        p->top=p->top-1;
        return p->arr[p->top+1];

}
int priority(char c)
{
    if(c=='^') 
        return 3;
    if(c=='*'||c=='/'||c=='%')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    if(c=='('||c==')')
        return 0;

}
int isOperand(char c)
{
    if(c=='^'||c=='*'||c=='/'||c=='%'||c=='+'||c=='-'||c=='('||c==')')
        return 0;
    else
        return 1;

}
void InToPo(struct Stack *infix, struct Stack *postfix, struct Stack *operator)
{
    while(!isEmpty(infix))
    {   int x;
        if(isOperand(infix->arr[infix->top])==1)
            push(postfix,pop(infix));
        else if(infix->arr[infix->top]=='(')
            push(operator,pop(infix));
        else if(infix->arr[infix->top]==')')
        {
            while(operator->arr[operator->top]!='(')
                push(postfix,pop(operator));
            x=pop(operator);
            x=pop(infix);
        }
        else if(priority(infix->arr[infix->top])>priority(operator->arr[operator->top]))
            push(operator,pop(infix));
        else
            push(postfix,pop(operator));

            
    }
    while(!isEmpty(operator))
    {
        push(postfix,pop(operator));
    }
}
int main()
{   char *str=(char *)calloc(MAX,sizeof(char));
    struct Stack *infix,*operator,*postfix;
    infix=(struct Stack *)malloc(sizeof(struct Stack));
    operator=(struct Stack *)malloc(sizeof(struct Stack));
    postfix=(struct Stack *)malloc(sizeof(struct Stack));
    init(infix);
    init(operator);
    init(postfix);
    printf("Enter the infix expression without spaces\n");
    scanf("%[^\n]s",str);
    for(int i=MAX-1;i>=0;i--)
    {
        if(str[i]!='\0')
        {
            push(infix,str[i]);
        }
    }
    InToPo(infix,postfix,operator);
    printf("The postfix expression is: \n");
    printf("%s",postfix);
    
    return 0;
}
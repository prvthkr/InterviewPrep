#include "stack.h"

bool isEmpty(Stack *Head) {
    if (Head == NULL) {
        return true;
    }
    return false;
}

#if CHAR
void push (Stack **Head, char ch) 
#else
void push (Stack **Head, int ch) 
#endif
{
    Stack *node = (Stack *) malloc(sizeof(Stack));
    
    node->ch = ch;
    node->next = (*Head);
    (*Head) = node;
}

#if CHAR
char pop(Stack **Head)
#else
int pop(Stack **Head)
#endif 
{
    if (isEmpty(*Head)) {
        return -1;
    }
#if CHAR
    char tmp;
#else
    int tmp;
#endif
    tmp = (*Head)->ch;
    
    Stack *node = (*Head);
    (*Head) = (*Head)->next;
    
    free(node);
    return tmp;
} 

#if CHAR
char top(Stack *Head)
#else
int top(Stack *Head)
#endif 
{
    if (isEmpty(Head)) {
        return -1;
    }
    return Head->ch;
}

void display(Stack *Head) 
{
    while(Head) {
#if CHAR
        printf("%c, ", Head->ch);
#else
        printf("%d, ", Head->ch);
#endif
        Head = Head->next;
    }
    printf("\n");
}

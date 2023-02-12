// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

typedef struct stack {
    char ch;
    struct stack *next;
} Stack;

bool isEmpty(Stack *Head) {
    if (Head == NULL) {
        return true;
    }
    return false;
}

void push (Stack **Head, char ch) {
    Stack *node = (Stack *) malloc(sizeof(Stack));
    
    node->ch = ch;
    node->next = (*Head);
    (*Head) = node;
}

char pop(Stack **Head) {
    
    if (isEmpty(*Head)) {
        return -1;
    }

    char tmp = (*Head)->ch;
    
    Stack *node = (*Head);
    (*Head) = (*Head)->next;
    
    free(node);
    return tmp;
} 

char top(Stack *Head) {
    if (isEmpty(Head)) {
        return -1;
    }
    return Head->ch;
}

void display(Stack *Head) {
    while(Head) {
        printf("%c ", Head->ch);
        Head = Head->next;
    }
    printf("\n");
}

void add_in_last(Stack **Head, char ch) {
    if (isEmpty(*Head)) {
        push(Head, ch);
    } else {
        char tmp = pop(Head);
        add_in_last(Head, ch);
        push(Head, tmp);
    }
}

void reverse_recursion(Stack **Head) {
    if (!isEmpty(*Head)) {
        char tmp = pop(Head);
        reverse_recursion(Head);
        add_in_last(Head, tmp);
    }
}

int main() {
    
    Stack *Head = NULL;
    
    push(&Head, 'p');
    push(&Head, 'r');
    push(&Head, 'a');
    push(&Head, 'n');
    push(&Head, 'a');
    push(&Head, 'v');
    printf("Before: ");
    display(Head);
    reverse_recursion(&Head);
    printf("After: ");
    display(Head);
    
    return 0;
}

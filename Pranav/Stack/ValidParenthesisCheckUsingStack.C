// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

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
    Stack *node = (Stack *) malloc(sizeof(sizeof(Stack)));
    
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

bool valid_par(char *str) {
    Stack *Head = NULL;

    for (int i = 0; str[i]; i++) {
        if ((str[i] == ')' && top(Head) == '(') || 
            (str[i] == ']' && top(Head) == '[') ||
            (str[i] == '}' && top(Head) == '{') ) {
            pop(&Head);
        } else {
            push(&Head, str[i]);
        }
    }
    
    if (isEmpty(Head)) {
        return true;
    }
    return false;
}

int main() {
    // Write C code here
    if (valid_par("(())")) {
        printf("true");    
    } else {
        printf("false");
    }

    return 0;
}

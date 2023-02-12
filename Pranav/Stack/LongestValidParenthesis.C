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

int valid_par(char *str) {
    Stack *Head = NULL;
    
    int small = 0;
    int mid = 0;
    int big = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ')' && top(Head) == '(') {
            small++;
            pop(&Head);
        } else if (str[i] == ']' && top(Head) == '[') {
            mid++;
            pop(&Head);
        } else if (str[i] == '}' && top(Head) == '{') {
            big++;
            pop(&Head);
        } else {
            push(&Head, str[i]);
        }
    }
    
    if (small > mid && small > big) {
        return small * 2;
    } else if (mid > small && mid > big) {
        return mid * 2;
    } else if (big > small && big > mid) {
        return big * 2;
    }
    
    return 0;
}

int main() {
    // Write C code here
    
    printf("Longest Valid Parenthesis is: %d\n",valid_par("(())"));
    printf("Longest Valid Parenthesis is: %d\n",valid_par(")"));
    return 0;
}
